PORTNAME=	asclock
PORTVERSION=	1.3
PORTREVISION=	0
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	AFTERSTEP/apps/asclock

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Afterstep clock with some language extensions
WWW=		https://web.archive.org/web/20000816095347/http://www.asclock.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake xorg
USE_XORG=	xpm xext x11
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/asclock share/man/man1/asclock.1.gz
PORTSCOUT=	limit:^1\.

OPTIONS_DEFINE=
OPTIONS_SINGLE=	LANG CLOCK
OPTIONS_SINGLE_LANG=	ENGLISH GERMAN PORTUGUESE DUTCH NORWEGIAN \
			ITALIAN SWEDISH SPANISH HUNGARIAN BRETON \
			FRENCH CZECH RUSSIAN UKRAINIAN SLOVENE \
			INDONESIAN DANISH
OPTIONS_SINGLE_CLOCK=	CLK2 COLOR CLK8
OPTIONS_DEFAULT=	ENGLISH CLK8
NO_OPTIONS_SORT=yes
ENGLISH_DESC=		day and month names
GERMAN_DESC=		day and month names
PORTUGUESE_DESC=	day and month names
DUTCH_DESC=		day and month names
NORWEGIAN_DESC=		day and month names
ITALIAN_DESC=		day and month names
SWEDISH_DESC=		day and month names
SPANISH_DESC=		day and month names
HUNGARIAN_DESC=		day and month names
BRETON_DESC=		day and month names
FRENCH_DESC=		day and month names
CZECH_DESC=		day and month names
RUSSIAN_DESC=		day and month names
UKRAINIAN_DESC=		day and month names
SLOVENE_DESC=		day and month names
INDONESIAN_DESC=	day and month names
DANISH_DESC=	day and month names
CLK2_DESC=	2bit greyscale (4 colors)
COLOR_DESC=	8bit AfterStep-colors (44 colors)
CLK8_DESC=	8bit NeXTStep -colors (74 colors)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MENGLISH}
ASCLOCK_LANG=	english
.endif
.if ${PORT_OPTIONS:MGERMAN}
ASCLOCK_LANG=	german
.endif
.if ${PORT_OPTIONS:MPORTUGUESE}
ASCLOCK_LANG=	portuguese
.endif
.if ${PORT_OPTIONS:MDUTCH}
ASCLOCK_LANG=	dutch
.endif
.if ${PORT_OPTIONS:MNORWEGIAN}
ASCLOCK_LANG=	norwegian
.endif
.if ${PORT_OPTIONS:MITALIAN}
ASCLOCK_LANG=	italian
.endif
.if ${PORT_OPTIONS:MSWEDISH}
ASCLOCK_LANG=	swedish
.endif
.if ${PORT_OPTIONS:MSPANISH}
ASCLOCK_LANG=	spanish
.endif
.if ${PORT_OPTIONS:MHUNGARIAN}
ASCLOCK_LANG=	hungarian
.endif
.if ${PORT_OPTIONS:MBRETON}
ASCLOCK_LANG=	breton
.endif
.if ${PORT_OPTIONS:MFRENCH}
ASCLOCK_LANG=	french
.endif
.if ${PORT_OPTIONS:MCZECH}
ASCLOCK_LANG=	czech
.endif
.if ${PORT_OPTIONS:MRUSSIAN}
ASCLOCK_LANG=	russian
.endif
.if ${PORT_OPTIONS:MUKRAINIAN}
ASCLOCK_LANG=	ukrainian
.endif
.if ${PORT_OPTIONS:MSLOVENE}
ASCLOCK_LANG=	slovene
.endif
.if ${PORT_OPTIONS:MINDONESIAN}
ASCLOCK_LANG=	indonesian
.endif
.if ${PORT_OPTIONS:MDANISH}
ASCLOCK_LANG=	danish
.endif
.if ${PORT_OPTIONS:MCLK2}
ASCLOCK_CLOCK=	clk2
.endif
.if ${PORT_OPTIONS:MCOLOR}
ASCLOCK_CLOCK=	color
.endif
.if ${PORT_OPTIONS:MCLK8}
ASCLOCK_CLOCK=	clk8
.endif

# default
ASCLOCK_LANG?=	english
ASCLOCK_CLOCK?=	clk8

pre-configure:
	${RM} ${WRKSRC}/month.xpm ${WRKSRC}/weekday.xpm ${WRKSRC}/clk.xpm
	(cd ${WRKSRC} && ${LN} -s ./${ASCLOCK_LANG}/month.xpm ./month.xpm)
	(cd ${WRKSRC} && ${LN} -s ./${ASCLOCK_LANG}/weekday.xpm ./weekday.xpm)
	(cd ${WRKSRC} && ${LN} -s ./xpm/${ASCLOCK_CLOCK}.xpm ./clk.xpm)

.include <bsd.port.mk>
