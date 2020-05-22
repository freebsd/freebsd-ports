# $FreeBSD$

PORTNAME=	nostt
DISTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	ik@sjmulder.nl
COMMENT=	Command line NOS Teletekst reader, the Dutch public teletext system

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

USE_GITHUB=	yes
GH_ACCOUNT=	sjmulder

MAKE_ARGS=	MANPREFIX=${PREFIX}/man

PLIST_FILES=	bin/nostt \
		man/man1/nostt.1.gz

.include <bsd.port.mk>
