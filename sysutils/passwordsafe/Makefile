PORTNAME=	passwordsafe
DISTVERSION=	1.20.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Popular secure and convenient password manager
WWW=		https://pwsafe.org

LICENSE=	ART20

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libuuid.so:misc/libuuid \
		libxerces-c.so:textproc/xerces-c3 \
		libqrencode.so:graphics/libqrencode
BUILD_DEPENDS=	zip:archivers/zip

CONFLICTS=	pwsafe

USES=		compiler:c++14-lang gmake pkgconfig xorg
USE_GITHUB=	yes
USE_WX=		3.0+
USE_XORG=	x11 xt xtst

OPTIONS_DEFINE=	NLS YUBIKEY
YUBIKEY_DESC=	Yubikey support
OPTIONS_SUB=	yes

NLS_USES=		gettext gettext-tools
YUBIKEY_LIB_DEPENDS=	libykpers-1.so:security/ykpers
YUBIKEY_MAKE_ENV_OFF=	NO_YUBI=yes

MAKE_ENV=	NO_QR=yes

GH_ACCOUNT=	pwsafe
GH_PROJECT=	${GH_ACCOUNT}

WX_COMPS=	wx
WANT_WX_VER=	3.0

LDFLAGS=	-L${PREFIX}/lib -lqrencode

ALL_TARGET=	unicoderelease

PORTSCOUT=	limit=^1\.

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
CXXFLAGS+=	-DPWS_BIG_ENDIAN
.else
CXXFLAGS+=	-DPWS_LITTLE_ENDIAN
.endif

post-patch:
.	for f in Makefile.freebsd help/Makefile.freebsd src/os/unix/Makefile \
		src/os/unix/dir.cpp src/ui/wxWidgets/Makefile
		${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/$f
.	endfor

post-build:
	${GMAKE} -C ${WRKSRC}/src/ui/wxWidgets/I18N mos
	${GMAKE} -C ${WRKSRC}/help all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ui/wxWidgets/GCCUnicodeRelease/pwsafe \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}/help
	${CP} ${WRKSRC}/help/help*.zip ${STAGEDIR}${DOCSDIR}/help

post-install-NLS-on:
.for	l in da de es fr it ko nl pl ru sv zh
	${MKDIR} ${STAGEDIR}${PREFIX}/locale/$l/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/src/ui/wxWidgets/I18N/mos/$l/LC_MESSAGES/pwsafe.mo \
		${STAGEDIR}${PREFIX}/locale/$l/LC_MESSAGES
.endfor

.include <bsd.port.mk>
