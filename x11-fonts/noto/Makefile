# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.003
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (meta port)

LICENSE=	OFL11

USES=		metaport

OPTIONS_DEFINE=	BASIC EXTRA JP KR SC TC
OPTIONS_DEFAULT=BASIC EXTRA JP KR SC TC

BASIC_DESC=	Install basic fonts set
EXTRA_DESC=	Install extra fonts set
JP_DESC=	Install Japanese fonts set
KR_DESC=	Install Korean fonts set
SC_DESC=	Install Simplified Chinese fonts set
TC_DESC=	Install Traditional Chinese fonts set

BASIC_RUN_DEPENDS=	noto-basic>=0:x11-fonts/noto-basic
EXTRA_RUN_DEPENDS=	noto-extra>=0:x11-fonts/noto-extra
JP_RUN_DEPENDS=		noto-jp>=0:x11-fonts/noto-jp
KR_RUN_DEPENDS=		noto-kr>=0:x11-fonts/noto-kr
SC_RUN_DEPENDS=		noto-sc>=0:x11-fonts/noto-sc
TC_RUN_DEPENDS=		noto-tc>=0:x11-fonts/noto-tc

.include <bsd.port.mk>
