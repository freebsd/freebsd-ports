# Created by: nagilum
# $FreeBSD$

PORTNAME=	nstxd
PORTVERSION=	1.1b6
CATEGORIES=	net
MASTER_SITES=	http://www.nagilum.org/nstx/ \
		http://ftp.debian.org/debian/pool/main/n/nstx/
DISTNAME=	nstx_1.1-beta6.orig

PATCH_SITES=	http://www.nagilum.org/nstx/  \
		http://ftp.debian.org/debian/pool/main/n/nstx/
PATCH_DIST_STRIP=	-p1
PATCHFILES=	nstx_1.1-beta6-4.diff.gz

MAINTAINER=	freebsd@nagilum.org
COMMENT=	DNS tunnel server

USE_RC_SUBR+=	nstxd

WRKSRC=		${WRKDIR}/nstx-1.1-beta6
SUB_FILES=	pkg-message

ALL_TARGET=	nstxd
INSTALL_TARGET=	nstxd

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nstxd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/nstxd.8 ${STAGEDIR}${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif	#NOPORTDOCS

.include <bsd.port.mk>
