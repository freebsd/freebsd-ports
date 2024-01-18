PORTNAME=	noto
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (meta port)
WWW=		https://fonts.google.com/noto

RUN_DEPENDS=	noto-sans>=0:x11-fonts/noto-sans \
		noto-serif>=0:x11-fonts/noto-serif

USES=		metaport

OPTIONS_DEFINE=	COLOREMOJI EMOJI EXTRA HK JP KR MONO SC SYMBOLS SYMBOLS2 TC
OPTIONS_DEFAULT=COLOREMOJI EMOJI EXTRA HK JP KR MONO SC SYMBOLS SYMBOLS2 TC

COLOREMOJI_DESC=Install color emoji font
EMOJI_DESC=	Install monochrome emoji font
EXTRA_DESC=	Install extra script-specific fonts
HK_DESC=	Install Traditional Chinese Hong Kong fonts set
JP_DESC=	Install Japanese fonts set
KR_DESC=	Install Korean fonts set
MONO_DESC=	Install monospace font
SC_DESC=	Install Simplified Chinese fonts set
SYMBOLS_DESC=	Install symbols font
SYMBOLS2_DESC=	Install symbols 2 font
TC_DESC=	Install Traditional Chinese fonts set

COLOREMOJI_RUN_DEPENDS=	noto-color-emoji>=0:x11-fonts/noto-color-emoji
EMOJI_RUN_DEPENDS=	noto-emoji>=0:x11-fonts/noto-emoji
EXTRA_RUN_DEPENDS=	noto-extra>=0:x11-fonts/noto-extra
HK_RUN_DEPENDS=		noto-hk>=0:x11-fonts/noto-hk
JP_RUN_DEPENDS=		noto-jp>=0:x11-fonts/noto-jp
KR_RUN_DEPENDS=		noto-kr>=0:x11-fonts/noto-kr
MONO_RUN_DEPENDS=	noto-sans-mono>=0:x11-fonts/noto-sans-mono
SC_RUN_DEPENDS=		noto-sc>=0:x11-fonts/noto-sc
SYMBOLS_RUN_DEPENDS=	noto-sans-symbols>=0:x11-fonts/noto-sans-symbols
SYMBOLS2_RUN_DEPENDS=	noto-sans-symbols-2>=0:x11-fonts/noto-sans-symbols-2
TC_RUN_DEPENDS=		noto-tc>=0:x11-fonts/noto-tc

.include <bsd.port.mk>
