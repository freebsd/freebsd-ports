# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox
DISTVERSION=	10.0.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${DISTVERSION}esr/source
DISTNAME=	${PORTNAME}-${DISTVERSION}esr.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.8.8:${PORTSDIR}/devel/nspr \
		nss>=3.13.1:${PORTSDIR}/security/nss \
		sqlite3>=3.7.7.1:${PORTSDIR}/databases/sqlite3 \
		cairo>=1.10.2_1,1:${PORTSDIR}/graphics/cairo \
		unzip:${PORTSDIR}/archivers/unzip

CONFLICTS_BUILD=	spidermonkey-*

USE_AUTOTOOLS=	autoconf213:env
LATEST_LINK=	firefox-esr
USE_GECKO=	gecko
CONFLICTS=	firefox-1[1-9].*
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
NO_MOZPKGINSTALL=yes

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--enable-application=browser \
		--enable-official-branding

OPTIONS_DEFINE=	PGO

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/mozilla-esr10

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == powerpc64
.if ${OSVERSION} < 900033
BROKEN=		Needs binutils 2.17.50 to build
.else
MOZ_EXPORT+=	UNAME_m="powerpc64"
CFLAGS+=	-mminimal-toc
.endif
.endif

.if ${PORT_OPTIONS:MPGO}
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
USE_PYTHON_BUILD=	yes
USE_DISPLAY=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"

.undef GNU_CONFIGURE
MOZ_OPTIONS+=	${CONFIGURE_TARGET}
MAKEFILE=	${WRKSRC}/client.mk
ALL_TARGET=	profiledbuild
MOZ_MK_OPTIONS+=PROFILE_GEN_SCRIPT='"${PYTHON_CMD} \
		@MOZ_OBJDIR@/_profile/pgo/profileserver.py"'
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.endif

.if !empty(CXX:M*clang++*)
CXXFLAGS+=	-Wno-return-type-c-linkage
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
	${MKDIR} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/share/pixmaps/${FIREFOX_ICON}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
