# New ports collection makefile for:	manencode
# Date created:		Sab  3 Mar 2007 21:52:49 CET
# Whom:                	Diego Depaoli <trebestie@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	manencode
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://csgib36.ifrance.com/Manencode/

MAINTAINER=	trebestie@gmail.com
COMMENT=	Utility to simply transcode your videos

RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder  \
		transcode:${PORTSDIR}/multimedia/transcode

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build rcc_build uic_build qmake_build

BROKEN=		master sites disappeared, project abandoned
EXPIRATION_DATE=2009-06-11

MANENCODEDIR=	${PREFIX}/share/${PORTNAME}
TRANSLATION=	_en
INTERFACE=	DVD.png DVDOK.png bt_play.png bt_stop.png \
		contrast.png cut_end.png cut_start.png debut.png \
		executer.png fin.png forward.png france.png \
		lumiere.png menu_select.png moins.png ombre.png \
		pb_pleine.png pb_vide.png plus.png poubelle.png \
		raz.png render.png rewind.png rotation1.png \
		rotation2.png saturation.png sauvegarde.png side_menu.png \
		son.png sstitres.png toolbar.PNG toolbar_2.PNG \
		uk.png window.png

WRKSRC=	${WRKDIR}/Manencode-${DISTVERSION}

DESKTOP_ENTRIES=	"Manencode" \
  			"Transcode your video" \
  			"" \
			"Manencode" \
			"Application;AudioVideo;" \
			false

do-configure:
	@cd ${WRKSRC} \
	&&  ${SETENV} ${CONFIGURE_ENV} ${QMAKE} -spec ${QMAKESPEC} \
	INCLUDEPATH+=${LOCALBASE}/include

pre-install:
	${MKDIR} ${MANENCODEDIR}/Interface

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Manencode ${MANENCODEDIR}/

.for file in ${INTERFACE}
	${INSTALL_DATA} ${WRKSRC}/Interface/${file} ${MANENCODEDIR}/Interface
.endfor

.for lang in ${TRANSLATION}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}${lang}.qm ${MANENCODEDIR}
.endfor

	${LN} -fs ${MANENCODEDIR}/Manencode ${PREFIX}/bin/

.include <bsd.port.mk>
