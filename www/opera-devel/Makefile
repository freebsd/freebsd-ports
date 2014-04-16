# $FreeBSD$

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://snapshot.opera.com/${MASTER_SITES_VER_PATH}/
PKGNAMESUFFIX=	-devel
DISTNAME=	${OPERA_NEXT}-${OPERA_VER}-${OPERA_BUILD}.${ARCH}.freebsd
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Blazingly fast, full-featured, standards-compliant browser (Next version)
IGNORE=		Development version is not currently active. Use www/opera instead of

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
BUILD_DEPENDS=	${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info

OPERA_NEXT?=	${PORTNAME}-next
OPERA_VER?=	12.00
OPERA_BUILD?=	1213
MASTER_SITES_VER_PATH=	unix/hwa_${OPERA_VER}-${OPERA_BUILD}
DATADIR=	${PREFIX}/share/${OPERA_NEXT}
DOCSDIR=	${PREFIX}/share/doc/${OPERA_NEXT}

USE_XZ=		yes
USE_XORG=	x11 xext sm ice xft xrender
USE_GNOME=	desktopfileutils
INSTALLS_ICONS=	yes

MAN1=		opera-next.1 opera-next-widget-manager.1
MANCOMPRESSED=	yes

NO_BUILD=	yes

OPTIONS_DEFINE=		CUPS VIDEO GTK2 KDE4
OPTIONS_DEFAULT=	CUPS VIDEO

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
.endif

.if ! ${PORT_OPTIONS:MVIDEO}
USE_GSTREAMER+=	vorbis ogg theora vp8 good
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
.endif

.if ${PORT_OPTIONS:MKDE4}
USE_KDE4+=	kdelibs
.endif

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

OPERA_ARCH=	${ARCH}

post-extract:
	@${MV} ${WRKSRC}/share/man ${WRKSRC}/man

do-install:
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${OPERA_NEXT}.1.gz ${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${OPERA_NEXT}-widget-manager.1.gz ${MANPREFIX}/man/man1/
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/install
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/install
	@(cd ${WRKSRC} && ./install --text --system --unattended)
	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib/browser_plugins|${LOCALBASE}/lib/npapi/symlinks/opera-devel|g' \
		${DATADIR}/defaults/pluginpath.ini
	@${RM} ${DATADIR}/defaults/pluginpath.ini.bak
	@${CP} ${PREFIX}/lib/opera-next/operapluginwrapper ${PREFIX}/lib/opera-next/operapluginwrapper.freebsd
	@${INSTALL_SCRIPT} ${PATCHDIR}/operapluginwrapper ${PREFIX}/lib/opera-next/
	-${LOCALBASE}/bin/update-desktop-database
	-${LOCALBASE}/bin/update-mime-database ${LOCALBASE}/share/mime

.include <bsd.port.post.mk>
