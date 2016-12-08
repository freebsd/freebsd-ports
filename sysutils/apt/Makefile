# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	apt
PORTVERSION=	0.6.46.4.1
PORTREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	apt_0.6.46.4-0.1

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Advanced front-end for dpkg

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/libpub.a:devel/publib
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		dpkg:archivers/dpkg \
		gpg:security/gnupg1
LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		bdb gettext iconv gmake shebangfix
SHEBANG_FILES=	dselect/install \
		dselect/setup \
		dselect/update
USE_LDCONFIG=	yes
NO_FILTER_SHLIBS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/db${BDB_VER} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/db${BDB_VER} -L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/apt-${PORTVERSION}

DPKGDIR?=	/var/db/dpkg
APTDIR?=	/var/db/apt
PLIST_SUB+=	APTDIR=${APTDIR:C,^/,,}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
BROKEN=		does not build
.endif

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
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-cache ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-cdrom ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-extracttemplates ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-ftparchive ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-get ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/apt-sortpkgs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/apt-key ${STAGEDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/bin/libapt-inst.so.1.1.0 ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libapt-inst.so.1.1.0 libapt-inst.so.1.1; ${LN} -sf libapt-inst.so.1.1.0 libapt-inst.so)
	${INSTALL_DATA} ${WRKSRC}/bin/libapt-pkg.so.3.11.0 ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libapt-pkg.so.3.11.0 libapt-pkg.so.3.11; ${LN} -sf libapt-pkg.so.3.11.0 libapt-pkg.so)

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/apt/keyrings

	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/cdrom ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/copy ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/file ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/ftp ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/gpgv ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/gzip ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/http ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/https ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/rred ${STAGEDIR}${PREFIX}/libexec/apt/methods
	${INSTALL_PROGRAM} ${WRKSRC}/bin/methods/rsh ${STAGEDIR}${PREFIX}/libexec/apt/methods
	(cd ${STAGEDIR}${PREFIX}/libexec/apt/methods; ${LN} -sf rsh ssh; ${LN} -sf gzip bzip2)

	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_DATA} ${WRKSRC}/scripts/dselect/desc.apt ${STAGEDIR}${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_DATA} ${WRKSRC}/scripts/dselect/names ${STAGEDIR}${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dselect/install ${STAGEDIR}${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dselect/setup ${STAGEDIR}${PREFIX}/libexec/dpkg/methods/apt
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/dselect/update ${STAGEDIR}${PREFIX}/libexec/dpkg/methods/apt

	@${MKDIR} ${STAGEDIR}${PREFIX}/include/apt-pkg
	${INSTALL_DATA} ${WRKSRC}/include/apt-pkg/* ${STAGEDIR}${PREFIX}/include/apt-pkg

	${INSTALL_MAN} ${WRKSRC}/docs/apt-extracttemplates.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/apt-ftparchive.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/apt-sortpkgs.1 ${STAGEDIR}${MANPREFIX}/man/man1

	${INSTALL_MAN} ${WRKSRC}/docs/apt.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/docs/apt_preferences.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/docs/sources.list.5 ${STAGEDIR}${MANPREFIX}/man/man5

	${INSTALL_MAN} ${WRKSRC}/docs/apt-cache.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-cdrom.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-config.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-get.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-key.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/docs/apt-secure.8 ${STAGEDIR}${MANPREFIX}/man/man8

	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/apt/conf.d
	${INSTALL_DATA} ${WRKSRC}/docs/examples/sources.list ${STAGEDIR}${PREFIX}/etc/apt/sources.list.sample
	${INSTALL_DATA} ${WRKSRC}/docs/examples/apt.conf ${STAGEDIR}${PREFIX}/etc/apt/apt.conf.sample

	@${MKDIR} ${STAGEDIR}${APTDIR}/cache/archives/partial
	@${MKDIR} ${STAGEDIR}${APTDIR}/state/lists/partial

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING.GPL ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.progress-reporting ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
