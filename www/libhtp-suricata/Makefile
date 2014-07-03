# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.2.14
PORTREVISION=	1
CATEGORIES=	www security
PKGNAMESUFFIX=	-suricata

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

USE_GITHUB=	yes
GH_ACCOUNT=	inliniac
GH_COMMIT=	0294c27

USES=		libtool pathfix pkgconfig
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libhtp-[0-9]*

PATHFIX_MAKEFILEIN=	Makefile.am
AUTOMAKE_ARGS+=		--force-missing --add-missing

.include <bsd.port.mk>
