PORTNAME=	tlwg-ttf
PORTVERSION=	0.6.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/thai-ttf/ \
		ftp://linux.thai.net/pub/thailinux/software/thai-ttf/
DISTNAME=	ttf-tlwg-${PORTVERSION}

MAINTAINER=	antumdeluge@gmail.com
COMMENT=	Collection of Thai TrueType fonts

LICENSE=	GPLv2

USES=		tar:xz

OPTIONS_MULTI=	TYPEFACE

OPTIONS_MULTI_TYPEFACE=	\
		TLW_MO TLW_TW TLW_TS TLW_TP \
		GAR KIN LAK LOM NOR PUR SAW UMP WAR

NTLW_MO=	TlwgMono
TLW_MO_DESC=	${NTLW_MO}
NTLW_TW=	TlwgTypewriter
TLW_TW_DESC=	${NTLW_TW}
NTLW_TS=	TlwgTypist
TLW_TS_DESC=	${NTLW_TS}
NTLW_TP=	TlwgTypo
TLW_TP_DESC=	${NTLW_TP}
NGAR=		Garuda
GAR_DESC=	${NGAR}
NKIN=		Kinnari
KIN_DESC=	${NKIN}
NLAK=		Laksaman
LAK_DESC=	${NLAK}
NLOM=		Loma
LOM_DESC=	${NLOM}
NNOR=		Norasi
NOR_DESC=	${NNOR}
NPUR=		Purisa
PUR_DESC=	${NPUR}
NSAW=		Sawasdee
SAW_DESC=	${NSAW}
NUMP=		Umpush
UMP_DESC=	${NUMP}
NWAR=		Waree
WAR_DESC=	${NWAR}

OPTIONS_DEFAULT=TLW_MO TLW_TW TLW_TS TLW_TP \
		GAR KIN LAK LOM NOR PUR SAW UMP WAR

OPTIONS_SUB=	yes
PLIST_SUB+=	NTLW_MO=${NTLW_MO} NTLW_TW=${NTLW_TW} NTLW_TS=${NTLW_TS} \
		NTLW_TP=${NTLW_TP} \
		NGAR=${NGAR} NKIN=${NKIN} NLAK=${NLAK} NLOM=${NLOM} \
		NNOR=${NNOR} NPUR=${NPUR} NSAW=${NSAW} NUMP=${NUMP} \
		NWAR=${NWAR} \
		BB=${BB} II=${II} LL=${LL} OO=${OO} \
		FONTS=${FONTS} XFONTS=${XFONTS} FONTSCONF=${FONTSCONF} \
		FONTSCONFD=${FONTSCONFD}

BB=		Bold
II=		Italic
LL=		Light
OO=		Oblique

TLW_MOFILES=	${NTLW_MO}.ttf ${NTLW_MO}-${BB}.ttf ${NTLW_MO}-${BB}${OO}.ttf \
		${NTLW_MO}-${OO}.ttf
TLW_TWFILES=	${NTLW_TW}.ttf ${NTLW_TW}-${BB}.ttf ${NTLW_TW}-${BB}${OO}.ttf \
		${NTLW_TW}-${OO}.ttf
TLW_TSFILES=	${NTLW_TS}.ttf ${NTLW_TS}-${BB}.ttf ${NTLW_TS}-${BB}${OO}.ttf \
		${NTLW_TS}-${OO}.ttf
TLW_TPFILES=	${NTLW_TP}.ttf ${NTLW_TP}-${BB}.ttf ${NTLW_TP}-${BB}${OO}.ttf \
		${NTLW_TP}-${OO}.ttf
GARFILES=	${NGAR}.ttf ${NGAR}-${BB}.ttf ${NGAR}-${BB}${OO}.ttf \
		${NGAR}-${OO}.ttf
KINFILES=	${NKIN}.ttf ${NKIN}-${BB}.ttf ${NKIN}-${BB}${II}.ttf \
		${NKIN}-${BB}${OO}.ttf ${NKIN}-${II}.ttf ${NKIN}-${OO}.ttf
LAKFILES=	${NLAK}.ttf ${NLAK}-${BB}.ttf ${NLAK}-${BB}${II}.ttf \
		${NLAK}-${II}.ttf
LOMFILES=	${NLOM}.ttf ${NLOM}-${BB}.ttf ${NLOM}-${BB}${OO}.ttf \
		${NLOM}-${OO}.ttf
NORFILES=	${NNOR}.ttf ${NNOR}-${BB}.ttf ${NNOR}-${BB}${II}.ttf \
		${NNOR}-${BB}${OO}.ttf ${NNOR}-${II}.ttf ${NNOR}-${OO}.ttf
PURFILES=	${NPUR}.ttf ${NPUR}-${BB}.ttf ${NPUR}-${BB}${OO}.ttf \
		${NPUR}-${OO}.ttf
SAWFILES=	${NSAW}.ttf ${NSAW}-${BB}.ttf ${NSAW}-${BB}${OO}.ttf \
		${NSAW}-${OO}.ttf
UMPFILES=	${NUMP}.ttf ${NUMP}-${BB}.ttf ${NUMP}-${BB}${OO}.ttf \
		${NUMP}-${LL}.ttf ${NUMP}-${LL}${OO}.ttf ${NUMP}-${OO}.ttf
WARFILES=	${NWAR}.ttf ${NWAR}-${BB}.ttf ${NWAR}-${BB}${OO}.ttf \
		${NWAR}-${OO}.ttf

TTFLABEL=	TTF

FONTS=		share/fonts/${TTFLABEL}/thai
XFONTS=		lib/X11/fonts/${TTFLABEL}/thai
FONTSCONF=	etc/fonts/conf.avail
FONTSCONFD=	etc/fonts/conf.d

FONTDEST=	${STAGEDIR}${LOCALBASE}/${XFONTS}
FONTLINKS=	${STAGEDIR}${LOCALBASE}/${FONTS}
CONFDEST=	${STAGEDIR}${LOCALBASE}/${FONTSCONF}
CONFLINKS=	${STAGEDIR}${LOCALBASE}/${FONTSCONFD}

TLW_MOCONF=	64-23-tlwg-mono.conf
#TLW_TWCONF=	64-24-tlwg-typewriter.conf
TLW_TWCONF_DATA='<?xml version="1.0"?>\n\
<!DOCTYPE fontconfig SYSTEM "fonts.dtd">\n\
<fontconfig>\
\n	<alias>\
\n		<family>monospace</family>\
\n		<prefer>\
\n			<family>TlwgTypewriter</family>\
\n		</prefer>\
\n	</alias>\
\n</fontconfig>'
TLW_TSCONF=	64-22-tlwg-typist.conf
TLW_TPCONF=	64-21-tlwg-typo.conf
GARCONF=	64-13-tlwg-garuda.conf 89-tlwg-garuda-synthetic.conf
KINCONF=	64-01-tlwg-kinnari.conf 89-tlwg-kinnari-synthetic.conf
LAKCONF=	64-15-laksaman.conf 89-tlwg-laksaman-synthetic.conf
LOMCONF=	64-12-tlwg-loma.conf 89-tlwg-loma-synthetic.conf
NORCONF=	64-02-tlwg-norasi.conf
#PURCONF=
#SAWCONF=
UMPCONF=	64-14-tlwg-umpush.conf 89-tlwg-umpush-synthetic.conf
WARCONF=	64-11-tlwg-waree.conf 89-tlwg-waree-synthetic.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTLW_MO}
INSTALLFONTS+=	${TLW_MOFILES}
INSTALLCONFS+=	${TLW_MOCONF}
.endif

.if ${PORT_OPTIONS:MTLW_TW}
INSTALLFONTS+=	${TLW_TWFILES}
#INSTALLCONFS+=	${TLW_TWCONF}
.endif

.if ${PORT_OPTIONS:MTLW_TS}
INSTALLFONTS+=	${TLW_TSFILES}
INSTALLCONFS+=	${TLW_TSCONF}
.endif

.if ${PORT_OPTIONS:MTLW_TP}
INSTALLFONTS+=	${TLW_TPFILES}
INSTALLCONFS+=	${TLW_TPCONF}
.endif

.if ${PORT_OPTIONS:MGAR}
INSTALLFONTS+=	${GARFILES}
INSTALLCONFS+=	${GARCONF}
.endif

.if ${PORT_OPTIONS:MKIN}
INSTALLFONTS+=	${KINFILES}
INSTALLCONFS+=	${KINCONF}
.endif

.if ${PORT_OPTIONS:MLAK}
INSTALLFONTS+=	${LAKFILES}
INSTALLCONFS+=	${LAKCONF}
.endif

.if ${PORT_OPTIONS:MLOM}
INSTALLFONTS+=	${LOMFILES}
INSTALLCONFS+=	${LOMCONF}
.endif

.if ${PORT_OPTIONS:MNOR}
INSTALLFONTS+=	${NORFILES}
INSTALLCONFS+=	${NORCONF}
.endif

.if ${PORT_OPTIONS:MPUR}
INSTALLFONTS+=	${PURFILES}
#INSTALLCONFS+=	${PURCONF}
.endif

.if ${PORT_OPTIONS:MSAW}
INSTALLFONTS+=	${SAWFILES}
#INSTALLCONFS+=	${SAWCONF}
.endif

.if ${PORT_OPTIONS:MUMP}
INSTALLFONTS+=	${UMPFILES}
INSTALLCONFS+=	${UMPCONF}
.endif

.if ${PORT_OPTIONS:MWAR}
LICENSE_COMB=	multi
LICENSE+=	MIT
INSTALLFONTS+=	${WARFILES}
INSTALLCONFS+=	${WARCONF}
.endif

do-build:

do-install:
	@${MKDIR} ${FONTDEST} ${FONTLINKS} ${CONFDEST} ${CONFLINKS}
#	@if [ ${PORT_OPTIONS:MTLW_TW} ]; then \
#		${ECHO_CMD} -e ${TLW_TWCONF_DATA} > \
#			${WRKSRC}/${FONTSCONF}/${TLW_TWCONF}; \
#	fi
	@for F in ${INSTALLFONTS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${F} \
			${FONTDEST}; \
		${LN} -s ${XFONTS}/$${F} ${FONTLINKS}; \
	done
	@for C in ${INSTALLCONFS}; do \
		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/$${C} \
			${CONFDEST}; \
		${LN} -s ${FONTSCONF}/$${C} ${CONFLINKS}; \
	done

#	@if [ ${PORT_OPTIONS:MTLW_MO} ]; then \
#		for F in ${TLW_MOFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/64-23-tlwg-mono.conf \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MTLW_TW} ]; then \
#		for F in ${TLW_TWFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MTLW_TS} ]; then \
#		for F in ${TLW_TSFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MTLW_TP} ]; then \
#		for F in ${TLW_TPFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MGAR} ]; then \
#		for F in ${GARFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MKIN} ]; then \
#		for F in ${KINFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MLAK} ]; then \
#		for F in ${LAKFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MLOM} ]; then \
#		for F in ${LOMFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MNOR} ]; then \
#		for F in ${NORFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MPUR} ]; then \
#		for F in ${PURFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MSAW} ]; then \
#		for F in ${SAWFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MUMP} ]; then \
#		for F in ${UMPFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;
#	@if [ ${PORT_OPTIONS:MWAR} ]; then \
#		for F in ${WARFILES}; do \
#			${INSTALL_DATA} ${WRKSRC}/$${F} \
#				${FONTDEST}; \
#			ln -s ${XFONTS}/$${F} ${FONTLINKS}; \
#		done; \
#		${INSTALL_DATA} ${WRKSRC}/${FONTSCONF}/ \
#			${CONFDEST}; \
#	fi;

.include <bsd.port.mk>
