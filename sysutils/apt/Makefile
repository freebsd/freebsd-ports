# New ports collection makefile for:	apt
# Date created:		23 October 2006
# Whom:			Nick Barkas <snb@threerings.net>
#
# $FreeBSD$

PORTNAME=	apt
PORTVERSION=	0.6.46.4.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	apt_0.6.46.4-0.1

MAINTAINER=	snb@FreeBSD.org
COMMENT=	Advanced front-end for dpkg

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/lib/libpub.a:${PORTSDIR}/devel/publib
RUN_DEPENDS=	${BUILD_DEPENDS} \
		dpkg:${PORTSDIR}/archivers/dpkg \
		gpg:${PORTSDIR}/security/gnupg1
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_BDB=	44+
USE_LDCONFIG=	yes
NO_FILTER_SHLIBS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/db${BDB_VER} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/db${BDB_VER} -L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
WRKSRC=		${WRKDIR}/apt-${PORTVERSION}

MAN1=		apt-extracttemplates.1 apt-ftparchive.1 apt-sortpkgs.1
MAN5=		apt.conf.5 apt_preferences.5 sources.list.5
MAN8=		apt-cache.8 apt-cdrom.8 apt-config.8 apt-get.8 apt-key.8 apt-secure.8

DPKGDIR?=	/var/db/dpkg
APTDIR?=	/var/db/apt
PLIST_SUB+=	APTDIR=${APTDIR:C,^/,,}

post-patch:
	${CP} ${FILESDIR}/https.cc ${FILESDIR}/https.h ${WRKSRC}/methods/
	${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' -e \
	's|@APTDIR@|${APTDIR}|g' -e 's|@DPKGDIR@|${DPKGDIR}|g' -e \
	's|@LOCALBASE@|${LOCALBASE}|g' \
		${WRKSRC}/apt-pkg/deb/debsystem.cc \
		${WRKSRC}/apt-pkg/init.cc \
		${WRKSRC}/cmdline/apt-key \
		${WRKSRC}/dselect/install \
		${WRKSRC}/dselect/setup \
		${WRKSRC}/dselect/update \
		${WRKSRC}/methods/gpgv.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-cache ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-cdrom ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-config ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-extracttemplates ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-ftparchive ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-get ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-sortpkgs ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/apt-key ${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/bin/libapt-inst.so.1.1.0 ${PREFIX}/lib
	(cd ${PREFIX}/lib; ${LN} -sf libapt-inst.so.1.1.0 libapt-inst.so.1.1; ${LN} -sf libapt-inst.so.1.1.0 libapt-inst.so)
	${INSTALL_DATA} ${WRKSRC}/bin/libapt-pkg.so.3.11.0 ${PREFIX}/lib
	(cd ${PREFIX}/lib; ${LN} -sf libapt-pkg.so.3.11.0 libapt-pkg.so.3.11; ${LN} -sf libapt-pkg.so.3.11.0 libapt-pkg.so)

	${MKDIR} ${PREFIX}/share/apt/keyrings

	${MKDIR} ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/cdrom ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/copy ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/file ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/ftp ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/gpgv ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/gzip ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/http ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/https ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/rred ${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/rsh ${PREFIX}/libexec/apt/methods
	(cd ${PREFIX}/libexec/apt/methods; ${LN} -sf rsh ssh; ${LN} -sf gzip bzip2)

	${MKDIR} ${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_DATA} ${WRKSRC}/scripts/dselect/desc.apt ${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_DATA} ${WRKSRC}/scripts/dselect/names ${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dselect/install ${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dselect/setup ${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dselect/update ${PREFIX}/libexec/dpkg/methods/apt

	${MKDIR} ${PREFIX}/include/apt-pkg
	for f in ${WRKSRC}/include/apt-pkg/*; do \
		${INSTALL_DATA} $${f} ${PREFIX}/include/apt-pkg; \
	done

	${INSTALL_MAN} ${WRKSRC}/docs/apt-extracttemplates.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/apt-ftparchive.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/apt-sortpkgs.1 ${MANPREFIX}/man/man1

	${INSTALL_MAN} ${WRKSRC}/docs/apt.conf.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/docs/apt_preferences.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/docs/sources.list.5 ${MANPREFIX}/man/man5

	${INSTALL_MAN} ${WRKSRC}/docs/apt-cache.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-cdrom.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-config.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-get.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-key.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-secure.8 ${MANPREFIX}/man/man8

	${MKDIR} ${PREFIX}/etc/apt/conf.d
	${INSTALL_DATA} ${WRKSRC}/docs/examples/sources.list ${PREFIX}/etc/apt/sources.list.sample
	${INSTALL_DATA} ${WRKSRC}/docs/examples/apt.conf ${PREFIX}/etc/apt/apt.conf.sample

	${MKDIR} ${APTDIR}/cache/archives/partial
	${MKDIR} ${APTDIR}/state/lists/partial

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING.GPL ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.progress-reporting ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	for f in ${WRKSRC}/docs/examples/*; do \
		${INSTALL_MAN} $${f} ${EXAMPLESDIR}; \
	done
.endif

post-install:
	if [ ! -f ${PREFIX}/etc/apt/sources.list ]; then \
		${CP} -p ${PREFIX}/etc/apt/sources.list.sample ${PREFIX}/etc/apt/sources.list; \
	fi
	if [ ! -f ${PREFIX}/etc/apt/apt.conf ]; then \
		${CP} -p ${PREFIX}/etc/apt/apt.conf.sample ${PREFIX}/etc/apt/apt.conf; \
	fi

.include <bsd.port.mk>
