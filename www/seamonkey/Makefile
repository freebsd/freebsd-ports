# Created by: eivind/dima/jseger
# $FreeBSD$

PORTNAME=	seamonkey
DISTVERSION=	2.49.2
MOZILLA_VER=	52 # above + 3
CATEGORIES?=	www mail news editors irc ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build1/source
DISTFILES=	${DISTNAME}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=	nspr>=4.13.1:devel/nspr \
		nss>=3.28.6:security/nss \
		libevent>=2.0.21_2:devel/libevent \
		harfbuzz>=1.4.1:print/harfbuzz \
		graphite2>=1.3.8:graphics/graphite2 \
		png>=1.6.25:graphics/png \
		libvorbis>=1.3.5,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		sqlite3>=3.17.0:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf-2.13:devel/autoconf213 \
		yasm:devel/yasm \
		zip:archivers/zip
#		soundtouch>=1.9.0:audio/soundtouch \

LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

SSP_UNSAFE=	yes
USE_GECKO=	gecko
USE_GL=		gl
USES=		tar:xz
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

MOZ_OPTIONS+=	--enable-application=suite

USE_MOZILLA=	-soundtouch
MOZ_PKGCONFIG_FILES=

OPTIONS_DEFINE=	LDAP LIGHTNING RUST
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=CANBERRA GTK3 LDAP LIGHTNING

LDAP_DESC?=	LDAP support for Mailnews

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.options.mk>

MOZSRC:=	${WRKSRC}/mozilla

.if ! ${PORT_OPTIONS:MLDAP}
MOZ_OPTIONS+=	--disable-ldap
.else
MOZ_OPTIONS+=	--enable-ldap
.endif
.if ${PORT_OPTIONS:MLIGHTNING}
MOZ_OPTIONS+=	--enable-calendar
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/suite/app/nsSuiteApp.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/mozilla/modules/libpref/init/all.js
	@${SED} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/${MOZILLA}.desktop

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${MOZSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${MOZSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include <bsd.port.mk>
