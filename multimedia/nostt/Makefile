PORTNAME=	nostt
DISTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	ik@sjmulder.nl
COMMENT=	Command line NOS Teletekst reader, the Dutch public teletext system
WWW=		https://github.com/sjmulder/nostt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

USE_GITHUB=	yes
GH_ACCOUNT=	sjmulder

MAKE_ARGS=	MANPREFIX=${PREFIX}/share/man

PLIST_FILES=	bin/nostt \
		share/man/man1/nostt.1.gz

.include <bsd.port.mk>
