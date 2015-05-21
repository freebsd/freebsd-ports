# Created by: kaworu
# $FreeBSD$

PORTNAME=	selenium
PORTVERSION=	0.6.1
CATEGORIES=	www
MASTER_SITES=	SFJP/${PORTNAME}/17210

MAINTAINER=	kaworu@users.sourceforge.jp
COMMENT=	Selenium is web application test tool!

HAS_CONFIGURE=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} 's,-o root -g wheel,,' ${WRKSRC}/configure

.include <bsd.port.mk>
