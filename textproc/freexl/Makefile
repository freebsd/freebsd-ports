# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	freexl
PORTVERSION=	1.0.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/freexl-sources/

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Library to extract valid data from within an Excel (.xls) spreadsheet

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_search_locale_charset=no
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake iconv libtool pathfix
USE_LDCONFIG=	yes

.include <bsd.port.mk>
