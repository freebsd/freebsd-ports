# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	3.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Malware identification and classification tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	plusvic

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		alias autoreconf libtool pathfix
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

.include <bsd.port.mk>
