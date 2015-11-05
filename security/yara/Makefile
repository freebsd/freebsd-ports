# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	3.4.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Malware identification and classification tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	plusvic

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		alias autoreconf libtool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
