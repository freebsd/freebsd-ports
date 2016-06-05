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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DNS tunnel server

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_RC_SUBR=	nstxd

WRKSRC=		${WRKDIR}/nstx-1.1-beta6
SUB_FILES=	pkg-message

ALL_TARGET=	nstxd
INSTALL_TARGET=	nstxd

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nstxd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/nstxd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
