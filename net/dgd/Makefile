# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.2p4
PORTREVISION=	2
CATEGORIES=	net lang games
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|} \
		ftp://ftp.dworkin.nl/pub/dgd/ \
		ftp://ftp.imaginary.com/pub/LPC/servers/DGD/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin's Generic Driver (network server)

NO_CDROM=	"no distribution to corporate environment"
RESTRICTED=	"license required for commercial use"

OPTIONS=	NETWORKING	"With networking kfuns"		off \
		ANSI		"Allow ANSI escape codes"	off

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_WRKSRC=	${WRKDIR}/dgd
ALL_TARGET=	install
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_NETWORKING)
PATCH_SITES+=	ftp://noname.franken.de/pub/dgd/
PATCHFILES+=	Network-1-DGD-1.2p3-patch.gz
PLIST_SUB+=	NETWORKING=""
.else
PLIST_SUB+=	NETWORKING="@comment "
.endif

.ifdef (WITH_ANSI)
PATCH_SITES+=	http://www.eyesbeyond.com/dgd/
PATCHFILES+=	ansi.diff
.endif

.if defined(WITH_NETWORKING) || defined(WITH_ANSI)
PATCH_SITES+=		${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|}
PATCH_DIST_STRIP=	-p1
PATCH_STRIP=		-p0 -F 3
.endif

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKDIR}/dgd/mud.dgd

.ifdef (WITH_NETWORKING)
post-configure:
	cd ${WRKDIR}/dgd/ && ${FIND} . -name '*.orig' -delete
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/driver ${PREFIX}/sbin/dgd
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/precomp ${PREFIX}/bin/precomp
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/dgd/mud.dgd \
		${PREFIX}/etc/${PORTNAME}/kernel.dgd
	${MKDIR} ${DATADIR}/kernel
	cd ${WRKDIR}/dgd/mud && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/kernel
	# Install an RC script for DGD
	${CAT} ${FILESDIR}/dgd.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
		${PREFIX}/etc/rc.d/dgd.sh.sample
	${CHMOD} a+x ${PREFIX}/etc/rc.d/dgd.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/Copyright ${DOCSDIR}
.ifdef (WITH_NETWORKING)
	${INSTALL_DATA} ${WRKDIR}/dgd/Copyright.NETWORK-PACKAGE ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/dgd/Credits ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/README ${DOCSDIR}
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
