# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-iptv
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.saunalahti.fi/~rahrenbe/vdr/iptv/files/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - IP television plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
PATCH_STRIP=	-p1
MAKE_ARGS=	IPTV_EXTSHELL=/bin/sh
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

PORTDOCS=	README HISTORY
PORTEXAMPLES=	channels.conf.iptv

OPTIONS_DEFINE=	DOCS EXAMPLES NLS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD}  -e 's|^\(CHANNELS_CONF[[:space:]]*\)[?]*\(=[[:space:]]*\).*|\1\2${PREFIX}/etc/vdr/channels.conf|;' \
		-e 's|^\(CHANNEL_SETTINGS_DIR[[:space:]]*\)[?]*\(=[[:space:]]*\)/etc|\1\2${PREFIX}/etc|;' \
		${WRKSRC}/iptv/vlc2iptv

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/vlcinput
	${INSTALL_DATA} ${FILESDIR}/vlcinput/*.conf ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/vlcinput
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/image.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/image.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/internetradio.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/internetradio.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/iptvstream-notrap.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/iptvstream-notrap.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/iptvstream.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/iptvstream.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/linein.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/linein.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/vlc2iptv \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/vlc2iptv.sample
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN}/webcam.sh \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/webcam.sh.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/channels.conf.iptv ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
