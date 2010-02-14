# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.4
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

OPTIONS=	NETWORKING	"With networking kfuns"		off

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_WRKSRC=	${WRKDIR}/dgd
ALL_TARGET=	install
MAKE_JOBS_UNSAFE=	yes

KERNELLIB_VERSION=	1.3
EXTRA_PATCHES=		${WRKDIR}/${KERNELLIB_VERSION}-${KERNELLIB_VERSION}.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_NETWORKING)
MASTER_SITES+=	http://wotf.org/downloads/${PORTNAME}/:4
DIST_FILES+=	Network-0.8-dgd-${PORTVERSION}.patch.gz:4
EXTRA_PATCHES+=	${WRKDIR}/Network-0.8-dgd-${PORTVERSION}.patch \
		${FILESDIR}/extrapatch-kernellib-net
PLIST_SUB+=	NETWORKING=""
.else
PLIST_SUB+=	NETWORKING="@comment "
.endif

post-extract:
	@${MV} ${WRKDIR}/kernellib ${WRKDIR}/dgd/

pre-patch:
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${KERNELLIB_VERSION}-${KERNELLIB_VERSION}.1.gz > ${WRKDIR}/${KERNELLIB_VERSION}-${KERNELLIB_VERSION}.1
.if defined(WITH_NETWORKING)
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/Network-0.8-dgd-${PORTVERSION}.patch.gz | ${SED} -e 's:^\*\*\* dgd/:*** :' -e 's:^--- dgd-net/:--- :'> ${WRKDIR}/Network-0.8-dgd-${PORTVERSION}.patch
.endif

post-patch:
	@${MV} ${WRKSRC}/host/Makefile.bsd ${WRKSRC}/host/Makefile
	@# There are here since the networking package modifies either these
	@# lines or lines near them so they cannot be applied as patches.
	@${REINPLACE_CMD} -e "s:^directory\([[:space:]]\)=\([[:space:]]\)\"[^\"]*\":directory\1=\2\"${DATADIR}/kernel\":" -e "s:tmp/swap:tmp/dgd.swap:" ${WRKDIR}/dgd/mud.dgd
	@${REINPLACE_CMD} -e "/^DEBUG/d" ${WRKSRC}/Makefile
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
.ifdef (WITH_NETWORKING)
	${INSTALL_DATA} ${WRKDIR}/dgd/Changelog.NET ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/dgd/COPYING ${DOCSDIR}
.ifdef (WITH_NETWORKING)
	${INSTALL_DATA} ${WRKDIR}/dgd/COPYING.NET ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/Copyright.NET ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/dgd/Credits ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/README ${DOCSDIR}
.ifdef (WITH_NETWORKING)
	${INSTALL_DATA} ${WRKDIR}/dgd/README.NET ${DOCSDIR}
.endif
	cd ${WRKDIR}/dgd/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

post-install:
	# Need a temporary directory for certain files
	${MKDIR} ${DATADIR}/tmp
	# Run package installation script
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} \
		POST-INSTALL
	# Set mudlib ownership
	-@${CHOWN} -h -R mud:mud ${DATADIR}

.include <bsd.port.post.mk>
