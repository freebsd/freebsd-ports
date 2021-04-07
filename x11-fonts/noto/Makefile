PORTNAME=	noto
PORTVERSION=	2.0
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (meta port)

LICENSE=	OFL11

USES=		metaport

OPTIONS_DEFINE=	BASIC EMOJI EXTRA HK JP KR SC TC
OPTIONS_DEFAULT=BASIC EMOJI EXTRA HK JP KR SC TC

BASIC_DESC=	Install basic fonts set
EXTRA_DESC=	Install extra fonts set
EMOJI_DESC=	Install emoji fonts set
HK_DESC=	Install Traditional Chinese Hong Kong fonts set
JP_DESC=	Install Japanese fonts set
KR_DESC=	Install Korean fonts set
SC_DESC=	Install Simplified Chinese fonts set
TC_DESC=	Install Traditional Chinese fonts set

BASIC_RUN_DEPENDS=	noto-basic>=0:x11-fonts/noto-basic
EMOJI_RUN_DEPENDS=	noto-emoji>=0:x11-fonts/noto-emoji
EXTRA_RUN_DEPENDS=	noto-extra>=0:x11-fonts/noto-extra
HK_RUN_DEPENDS=		noto-hk>=0:x11-fonts/noto-hk
JP_RUN_DEPENDS=		noto-jp>=0:x11-fonts/noto-jp
KR_RUN_DEPENDS=		noto-kr>=0:x11-fonts/noto-kr
SC_RUN_DEPENDS=		noto-sc>=0:x11-fonts/noto-sc
TC_RUN_DEPENDS=		noto-tc>=0:x11-fonts/noto-tc

.include <bsd.port.mk>
