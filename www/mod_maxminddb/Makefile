PORTNAME=	mod_maxminddb
PORTVERSION=	1.3.0
PORTREVISION=	0
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	MaxMind DB Apache Module
WWW=		https://github.com/maxmind/mod_maxminddb

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		apache autoreconf compiler:c11 gmake localbase
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBEXECDEST%%|${STAGEDIR}${PREFIX}/${APACHEMODDIR}|g' ${WRKSRC}/src/Makefile.am

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.mk>
