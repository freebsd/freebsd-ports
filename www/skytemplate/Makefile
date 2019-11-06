# Created by: Mun-Kyo Seo <munggo@gmail.com>
# $FreeBSD$

PORTNAME=	skytemplate
PORTVERSION=	1.4.0
CATEGORIES=	www
MASTER_SITES=	http://daddy.withsky.net/SkyTemplate/download/ \
		http://mirror.pmy.lv/SkyTemplate/download/
DISTNAME=	SkyTemplate.v${PORTVERSION:S/.//g}

MAINTAINER=	munggo@gmail.com
COMMENT=	Yet another PHP compiling template engine

BROKEN=		unfetchable

USES=		php:web
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.php ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/SkyTpl
	${INSTALL_DATA} ${WRKSRC}/SkyTpl/* ${STAGEDIR}${DATADIR}/SkyTpl

.include <bsd.port.mk>
