# Created by: Roger Leigh <rleigh@codelibre.net>

PORTNAME=	xalan-c
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	APACHE/xalan/xalan-c/sources
DISTNAME=	xalan_c-${PORTVERSION}

MAINTAINER=	rleigh@apache.org
COMMENT=	XSLT processor from the Apache XML Project

LICENSE=	APACHE20

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_ARGS=	-Dmsgloader=inmemory -Dmessage-locale=en_US

OPTIONS_DEFINE=	ICU
OPTIONS_DEFAULT=	ICU
OPTIONS_SUB=	yes

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_DESC=	Use ICU for transcoding
ICU_CMAKE_ON=	-Dtranscoder=icu
ICU_CMAKE_OFF=	-Dtranscoder=default

.include <bsd.port.mk>
