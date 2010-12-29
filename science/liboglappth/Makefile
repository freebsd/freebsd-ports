# New ports collection makefile for: liboglappth
# Date created:			2008/8/21
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	liboglappth
PORTVERSION=	0.98
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/current/ \
		http://bioinformatics.org/ghemical/download/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

GNU_CONFIGURE=  yes

USE_GL=		glut
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"       \
		CXXFLAGS="-I${LOCALBASE}/include"       \
		CFLAGS="-I${LOCALBASE}/include"         \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
