# Created by: Jose M. Alcaide <jose@we.lc.ehu.es>
# $FreeBSD$

PORTNAME=	tcpflow
PORTVERSION=	1.5.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://digitalcorpora.org/downloads/${PORTNAME}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Program that captures data transmitted as part of TCP connections

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/icl/interval.hpp:devel/boost-libs
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		python:2.7 ssl xorg
USE_XORG=	pixman
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_md_MD5=no \
		ac_cv_header_tre_tre_h=no ac_cv_lib_tre_tre_regcomp=no \
		ac_cv_header_sqlite3_h=no ac_cv_lib_sqlite3_sqlite3_libversion=no
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/tcpflow man/man1/tcpflow.1.gz

.include <bsd.port.mk>
