# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsass
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

AUTOMAKE_ARGS=	--add-missing

GH_ACCOUNT=	sass
GH_COMMIT=	0388a62
GH_TAGNAME=	v${PORTVERSION}

INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

USES=		libtool pathfix
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_GITHUB=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
