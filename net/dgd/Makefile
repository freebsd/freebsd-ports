# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.4.1
CATEGORIES=	net lang games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S|%SUBDIR%|${PORTNAME}-osr|}:1 \
		http://ftp.dworkin.nl/kernellib/:2 \
		http://ftp.dworkin.nl/kernellib/patches/:3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1 \
		kernellib-${KERNELLIB_VERSION}${EXTRACT_SUFX}:2 \
		${KERNELLIB_VERSION}-${KERNELLIB_VERSION}.1.gz:3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		kernellib-${KERNELLIB_VERSION}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin's Game Driver

OPTIONS=	NETWORKING	"With networking kfuns"		off \
		DUMP		"With dump kfuns"		off

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_WRKSRC=	${WRKDIR}/dgd
ALL_TARGET=	install
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	EXTRA_DEFINES="$(EXTRA_DEFINES)"

KERNELLIB_VERSION=	1.3
EXTRA_PATCHES=		${WRKDIR}/${KERNELLIB_VERSION}-${KERNELLIB_VERSION}.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

EXTRA_DEFINES=

.if defined(WITH_NETWORKING)
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-kernellib-net
PLIST_SUB+=	NETWORKING=""
EXTRA_DEFINES+=	-DNETWORK_EXTENSIONS
.else
PLIST_SUB+=	NETWORKING="@comment "
.endif

.if defined(WITH_DUMP)
EXTRA_DEFINES+=	-DDUMP_FUNCS
.endif

post-extract:
	@${MV} ${WRKDIR}/kernellib ${WRKDIR}/dgd/

pre-patch:
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${KERNELLIB_VERSION}-${KERNELLIB_VERSION}.1.gz > ${WRKDIR}/${KERNELLIB_VERSION}-${KERNELLIB_VERSION}.1

post-patch:
	@${MV} ${WRKSRC}/host/Makefile.bsd ${WRKSRC}/host/Makefile
	@${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKDIR}/dgd/mud.dgd
	@cd ${WRKDIR}/dgd/ && ${FIND} . -name '*.orig' -delete

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/driver ${PREFIX}/sbin/dgd
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/precomp ${PREFIX}/bin/precomp
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/dgd/mud.dgd \
		${PREFIX}/etc/${PORTNAME}/kernel.dgd
	${MKDIR} ${DATADIR}/kernel
	cd ${WRKDIR}/dgd/kernellib && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/kernel
	@# Install an RC script for DGD
	${CAT} ${FILESDIR}/dgd.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
		${PREFIX}/etc/rc.d/dgd.sh.sample
	${CHMOD} a+x ${PREFIX}/etc/rc.d/dgd.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/Changelog ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/Credits ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/README ${DOCSDIR}
	cd ${WRKDIR}/dgd/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
	@# Need a temporary directory for certain files
	@${MKDIR} ${DATADIR}/tmp
	@# Run package installation script
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} \
		POST-INSTALL
	@# Set mudlib ownership
	-@${CHOWN} -h -R mud:mud ${DATADIR}

.include <bsd.port.post.mk>
