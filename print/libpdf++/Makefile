# ex:ts=8
# Ports collection makefile for:	libpdf++
# Date created:			Jan 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libpdf++
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://libpdfxx.sourceforge.net/
MASTER_SITE_SUBDIR=	libpdfxx
DISTNAME=	libpdfdoc-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library to generate PDF files

BUILD_DEPENDS=	${LOCALBASE}/include/boost/any.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${LOCALBASE}/include/boost/any.hpp:${PORTSDIR}/devel/boost

USE_AUTOMAKE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
USE_GCC=	3.1
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
.else
CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
.endif

.include <bsd.port.post.mk>
