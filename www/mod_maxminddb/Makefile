# $FreeBSD$

PORTNAME=	mod_maxminddb
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	MaxMind DB Apache Module

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		apache:2.4+ autoreconf gmake localbase
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBEXECDEST%%|${STAGEDIR}${PREFIX}/${APACHEMODDIR}|g' ${WRKSRC}/src/Makefile.am

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.mk>
