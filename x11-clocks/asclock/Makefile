# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	asclock
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	XCONTRIB/applications
DISTNAME=	${PORTNAME}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Afterstep clock with some language extensions

LICENSE=	BSD2CLAUSE

CONFLICTS=	asclock-gtk-[0-9]* asclock-xlib-[0-9]*

USES=		imake tar:tgz xorg
USE_XORG=	xpm xext x11
PLIST_FILES=	bin/asclock man/man1/asclock.1.gz

OPTIONS_DEFINE=
OPTIONS_SINGLE=	LANG
OPTIONS_SINGLE_LANG=	EN DE PT NL NO IT SE ES HU BRE FR CZ
OPTIONS_DEFAULT=	EN
NO_OPTIONS_SORT=yes
EN_DESC=	english
DE_DESC=	german
PT_DESC=	portuguese
NL_DESC=	dutch
NO_DESC=	norwegian
IT_DESC=	italian
SE_DESC=	swedish
ES_DESC=	spanish
HU_DESC=	hungarian
BRE_DESC=	breton
FR_DESC=	french
CZ_DESC=	czech

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDE}
ASCLOCK_LANG=	german
.endif
.if ${PORT_OPTIONS:MPT}
ASCLOCK_LANG=	portuguese
.endif
.if ${PORT_OPTIONS:MNL}
ASCLOCK_LANG=	dutch
.endif
.if ${PORT_OPTIONS:MNO}
ASCLOCK_LANG=	norwegian
.endif
.if ${PORT_OPTIONS:MIT}
ASCLOCK_LANG=	italian
.endif
.if ${PORT_OPTIONS:MSE}
ASCLOCK_LANG=	swedish
.endif
.if ${PORT_OPTIONS:MES}
ASCLOCK_LANG=	spanish
.endif
.if ${PORT_OPTIONS:MHU}
ASCLOCK_LANG=	hungarian
.endif
.if ${PORT_OPTIONS:MBRE}
ASCLOCK_LANG=	breton
.endif
.if ${PORT_OPTIONS:MFR}
ASCLOCK_LANG=	french
.endif
.if ${PORT_OPTIONS:MCZ}
ASCLOCK_LANG=	czech
.endif

# default
ASCLOCK_LANG?=	english

pre-configure:
	${RM} ${WRKSRC}/month.xpm ${WRKSRC}/weekday.xpm
	(cd ${WRKSRC} && ${LN} -s ./${ASCLOCK_LANG}/month.xpm ./month.xpm)
	(cd ${WRKSRC} && ${LN} -s ./${ASCLOCK_LANG}/weekday.xpm ./weekday.xpm)

.include <bsd.port.mk>
