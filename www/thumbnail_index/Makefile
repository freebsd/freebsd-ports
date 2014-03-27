# Created by: Yoshiro MIHIRA <sanpei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thumbnail_index
PORTVERSION=	1998.08.10
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thumbnail_index/
DISTNAME=	${PORTNAME}_10aug1998

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Make an HTML index file for a bunch of images

RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		pnmscale:${PORTSDIR}/graphics/netpbm

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/thumbnail_index ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/thumbnail_reap ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/thumbnail_index.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
