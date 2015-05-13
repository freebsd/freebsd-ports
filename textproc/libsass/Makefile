# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsass
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

GH_ACCOUNT=	sass

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

USES=		autoreconf libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
