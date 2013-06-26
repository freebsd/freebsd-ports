# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	22.0
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source
DISTNAME=	${PORTNAME}-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.9.6:${PORTSDIR}/devel/nspr \
		nss>=3.14.3:${PORTSDIR}/security/nss \
		sqlite3>=3.7.14.1:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		cairo>=1.10.2_1,1:${PORTSDIR}/graphics/cairo \
		unzip:${PORTSDIR}/archivers/unzip

USE_AUTOTOOLS=	autoconf213:env
USE_PYTHON_BUILD=-2.7
OBJDIR_BUILD=	# in-tree build broken after bug 789837
USE_GECKO=	gecko
CONFLICTS=	firefox-24.* firefox-1[07].*
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	# empty
MOZILLA_NAME=	Firefox

MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
ALL_TARGET=	default
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_DOS2UNIX=	media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp
NO_MOZPKGINSTALL=yes

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--enable-application=browser \
		--enable-official-branding

OPTIONS_DEFINE=	PGO WEBRTC
OPTIONS_DEFAULT=WEBRTC

.include "${.CURDIR}/../../www/firefox/Makefile.options"

# OSS is gone after bug 852401
OPTIONS_SINGLE_AUDIO:=${OPTIONS_SINGLE_AUDIO:S/OSS//}

.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/mozilla-release

.if ${PORT_OPTIONS:MPGO}
USE_GCC?=	yes
USE_DISPLAY=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"

.undef GNU_CONFIGURE
MOZ_OPTIONS+=	${CONFIGURE_TARGET}
MAKEFILE=	${WRKSRC}/client.mk
ALL_TARGET=	profiledbuild
MOZ_MK_OPTIONS+=PROFILE_GEN_SCRIPT="${PYTHON_CMD} \
		@MOZ_OBJDIR@/_profile/pgo/profileserver.py"
.endif

pre-extract:
.if ${PORT_OPTIONS:MPGO}
	@${ECHO} "*****************************************************************"
	@${ECHO} "**************************** attention **************************"
	@${ECHO} "*****************************************************************"
	@${ECHO} "To build Firefox with PGO support you need a running X server and"
	@${ECHO} "   build this port with an user who could access the X server!   "
	@${ECHO} ""
	@${ECHO} "During the build a Firefox instance will start and run some test."
	@${ECHO} "      Do not interrupt or close Firefox during this tests!       "
	@${ECHO} "*****************************************************************"
	@sleep 10
.endif

post-extract:
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		-e '/^SQLITE_VERSION/s/=.*/=3.7.14.1/' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

port-pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLISTF}
	${ECHO_CMD} "@dirrmtry share/applications" >> ${PLISTD}
	${ECHO_CMD} 'share/pixmaps/${FIREFOX_ICON}' >> ${PLISTF}

post-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/share/pixmaps/${FIREFOX_ICON}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
