# New ports collection makefile for:	gtk-youtube-viewer
# Date created:		13 August 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	gtk-youtube-viewer
PORTVERSION=	2.0.5
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nemysis@gmx.ch
COMMENT=	GTK Search and play YouTube videos streaming in MPlayer

LICENSE=	GPLv3

RUN_DEPENDS=	p5-XML-Fast>=0:${PORTSDIR}/net/p5-XML-Fast \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		mplayer:${PORTSDIR}/multimedia/mplayer

OPTIONS_DEFINE=	DATA GCAP
GCAP_DESC=	GCAP support
OPTIONS_DEFAULT=	DATA

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_PERL5_RUN=	yes
NO_BUILD=	yes
PROJECTHOST=	trizen

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		share/applications/${PORTNAME}.desktop
PLIST_DIRSTRY=	share/applications

PORTDATA=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCAP}
RUN_DEPENDS+=	${LOCALBASE}/bin/gcap:${PORTSDIR}/multimedia/gcap
.endif

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -e "s|#!/usr/bin/perl|#!${PERL}|g" gtk-youtube-viewer.pl \
		youtube-viewer && ${REINPLACE_CMD} -e "s|/usr/share/|${PREFIX}/share/|g" gtk-youtube-viewer)

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/youtube-viewer ${DATADIR}

# Data
.if ${PORT_OPTIONS:MDATA}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "icons lib" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pl ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.glade ${DATADIR}
.endif

# Pixmaps and Desktop
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications/

.include <bsd.port.mk>
