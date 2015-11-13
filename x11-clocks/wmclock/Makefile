# Created by: Per Otterstr=F6m <pelle@fukt.bth.se>
# $FreeBSD$

PORTNAME=	wmclock
PORTVERSION=	1.0.16
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable clock applet for Window Maker

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/dockapps-daaf3aa

USES=		autoreconf gmake pkgconfig
USE_XORG=	xpm
GNU_CONFIGURE=	yes

OPTIONS_SINGLE=		NLS
OPTIONS_SINGLE_NLS=	LANG_BR LANG_CS LANG_DA LANG_DE LANG_ES \
			LANG_FR LANG_FR_ALT LANG_HR LANG_HU LANG_ID \
			LANG_IT LANG_NB LANG_NL LANG_PL LANG_PT \
			LANG_RU LANG_SL LANG_SV LANG_US LANG_UK
OPTIONS_DEFAULT=	LANG_US

LANG_BR_CONFIGURE_ON=	--with-lang=breton
LANG_CS_CONFIGURE_ON=	--with-lang=czech
LANG_DA_CONFIGURE_ON=	--with-lang=danish
LANG_DE_CONFIGURE_ON=	--with-lang=german
LANG_ES_CONFIGURE_ON=	--with-lang=spanish
LANG_FR_CONFIGURE_ON=	--with-lang=french
LANG_FR_ALT_DESC=	French (alternative) language support
LANG_FR_ALT_CONFIGURE_ON=	--with-lang=french2
LANG_HR_CONFIGURE_ON=	--with-lang=croatian
LANG_HU_CONFIGURE_ON=	--with-lang=hungarian
LANG_ID_CONFIGURE_ON=	--with-lang=indonesian
LANG_IT_CONFIGURE_ON=	--with-lang=italian
LANG_NB_CONFIGURE_ON=	--with-lang=norwegian
LANG_NL_CONFIGURE_ON=	--with-lang=dutch
LANG_PL_CONFIGURE_ON=	--with-lang=polish
LANG_PT_CONFIGURE_ON=	--with-lang=portuguese
LANG_RU_CONFIGURE_ON=	--with-lang=russian
LANG_SL_CONFIGURE_ON=	--with-lang=slovene
LANG_SV_CONFIGURE_ON=	--with-lang=swedish
LANG_US_CONFIGURE_ON=	--with-lang=english
LANG_UK_CONFIGURE_ON=	--with-lang=ukrainian

post-patch:
	@${REINPLACE_CMD} -e \
		's|mois_xpm|month_xpm|' ${WRKSRC}/lang.french2/month.xpm
	@${REINPLACE_CMD} -e \
		's|jours|weekday_xpm|' ${WRKSRC}/lang.french2/weekday.xpm

.include <bsd.port.mk>
