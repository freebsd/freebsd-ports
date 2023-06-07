PORTNAME=	angie
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	https://download.angie.software/files/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Efficient, powerful and scalable web server
WWW=		https://angie.software/en/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		gmake ssl

HAS_CONFIGURE=	yes
ALL_TARGET=

CONFIGURE_ARGS=	--with-openssl=${LOCALBASE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/angie/sbin/angie

.include <bsd.port.mk>
