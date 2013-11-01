# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	24.1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}esr/source
PKGNAMESUFFIX=	-esr
DISTNAME=	${PORTNAME}-${DISTVERSION}esr.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.10:${PORTSDIR}/devel/nspr \
		nss>=3.15:${PORTSDIR}/security/nss \
		sqlite3>=3.7.17:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		cairo>=1.10.2_1,1:${PORTSDIR}/graphics/cairo \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

USE_AUTOTOOLS=	autoconf213:env
USE_PYTHON_BUILD=-2.7
OBJDIR_BUILD=	# in-tree build broken after bug 789837
USE_GECKO=	gecko
CONFLICTS=	firefox-2[0-35-9].* firefox-1[1-689].*
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	# empty
MOZILLA_NAME=	Firefox

WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
ALL_TARGET=	default
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GL=		gl
USE_DOS2UNIX=	media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp
NO_MOZPKGINSTALL=yes

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--enable-application=browser \
		--enable-official-branding

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/mozilla-esr24

post-extract:
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

port-pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLISTF}
	${ECHO_CMD} 'share/pixmaps/${FIREFOX_ICON}' >> ${PLISTF}

post-install:
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/share/pixmaps/${FIREFOX_ICON}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
