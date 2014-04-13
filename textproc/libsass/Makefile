# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsass
PORTVERSION=	1.0.1
#PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

AUTOMAKE_ARGS=	--add-missing

GH_ACCOUNT=	hcatlin
GH_COMMIT=	0388a62
GH_TAGNAME=	v${PORTVERSION}

INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USES=	pathfix

.include <bsd.port.mk>
