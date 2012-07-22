# New ports collection makefile for:	vdr-plugin-remote
# Date created:		Sun Aug 29 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-iptv
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.saunalahti.fi/~rahrenbe/vdr/iptv/files/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - IP television plugin

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
PORTEXAMPLES=	channels.conf.iptv
MAKE_JOBS_SAFE=	yes
MAKE_ARGS+=	IPTV_EXTSHELL=/bin/sh
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD} 's|^\(CHANNELS_CONF[[:space:]]*\)[?]*\(=[[:space:]]*\).*|\1\2${PREFIX}/etc/vdr/channels.conf|;'\\
		's|^\(CHANNEL_SETTINGS_DIR[[:space:]]*\)[?]*\(=[[:space:]]*\)/etc|\1\2${PREFIX}/etc|;'\
		${WRKSRC}/iptv/vlc2iptv

post-install: post-install-pluginlocales
	@${MKDIR} ${PREFIX}/etc/vdr/plugins/${PLUGIN}
	@${MKDIR} ${PREFIX}/etc/vdr/plugins/${PLUGIN}/vlcinput
	@${INSTALL_DATA} ${FILESDIR}/vlcinput/*.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}/vlcinput
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/image.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}/image.sh.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/image.sh ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/image.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/internetradio.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}/internetradio.sh.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/internetradio.sh ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/internetradio.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/iptvstream-notrap.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}/iptvstream-notrap.sh.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/iptvstream-notrap.sh ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/iptvstream-notrap.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/iptvstream.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}/iptvstream.sh.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/iptvstream.sh ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/iptvstream.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/linein.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}/linein.sh.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/linein.sh ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/linein.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/vlc2iptv ${PREFIX}/etc/vdr/plugins/${PLUGIN}/vlc2iptv.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/vlc2iptv ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/vlc2iptv ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/webcam.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}/webcam.sh.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/webcam.sh ]; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/webcam.sh ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/channels.conf.iptv ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
