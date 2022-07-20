PORTNAME=	freexl
DISTVERSION=	1.0.6
CATEGORIES=	textproc
MASTER_SITES=	https://www.gaia-gis.it/gaia-sins/freexl-sources/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library to extract valid data from within an Excel (.xls) spreadsheet

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual

USES=		cpe gmake iconv libtool pathfix
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_search_locale_charset=no
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
