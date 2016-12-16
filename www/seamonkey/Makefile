# Created by: eivind/dima/jseger
# $FreeBSD$

PORTNAME=	seamonkey
DISTVERSION=	2.46
MOZILLA_VER=	49 # above + 3
PORTREVISION=	1
CATEGORIES?=	www mail news editors irc ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build9/source
DISTFILES=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=	nspr>=4.12:devel/nspr \
		nss>=3.25:security/nss \
		libevent2>=2.0.21_2:devel/libevent2 \
		soundtouch>=1.9.0:audio/soundtouch \
		harfbuzz>=1.2.6:print/harfbuzz \
		graphite2>=1.3.8:graphics/graphite2 \
		png>=1.6.21:graphics/png \
		libvorbis>=1.3.5,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		sqlite3>=3.13:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf-2.13:devel/autoconf213 \
		yasm:devel/yasm \
		zip:archivers/zip

LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

SSP_UNSAFE=	yes
USE_GECKO=	gecko
USE_GL=		gl
USES=		tar:xz
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--enable-application=suite

USE_MOZILLA=	# empty
MOZ_PKGCONFIG_FILES=

BROKEN_aarch64=		Fails to link: error adding symbols: File in wrong format

OPTIONS_DEFINE=	LDAP RUST
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=CANBERRA GTK2 LDAP

LDAP_DESC?=	LDAP support for Mailnews

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.options.mk>

WRKSRC:=	${WRKDIR}/${PORTNAME}-${DISTVERSION}
MOZSRC:=	${WRKSRC}/mozilla

XPI_LIBDIR=	${PREFIX}/lib/xpi

.if ! ${PORT_OPTIONS:MLDAP}
MOZ_OPTIONS+=	--disable-ldap
.else
MOZ_OPTIONS+=	--enable-ldap
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
