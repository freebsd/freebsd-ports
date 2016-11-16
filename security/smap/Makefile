# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	smap
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.wormulon.net/smap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIP scanner and identifier

USES=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smap ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fingerprint.db ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
