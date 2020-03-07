# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	radius
DISTVERSION=	1.4.0b1
CATEGORIES=	net security pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Radius client library for PHP

LICENSE=	BSD3CLAUSE

USES=		php:pecl

CONFIGURE_ARGS=	--enable-radius

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
