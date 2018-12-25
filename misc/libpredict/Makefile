# $FreeBSD$

PORTNAME=	libpredict
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Satellite orbit prediction library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	la1k
USE_LDCONFIG=	yes

PLIST_FILES=	include/predict/predict.h \
		lib/libpredict.so \
		lib/libpredict.so.${DISTVERSION:R:R} \
		lib/libpredict.so.${DISTVERSION} \
		libdata/pkgconfig/predict.pc

.include <bsd.port.mk>
