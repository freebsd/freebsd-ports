# $FreeBSD$

PORTNAME=	passwordsafe
DISTVERSION=	1.03BETA
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Popular secure and convenient password manager

LICENSE=	ART20

NOT_FOR_ARCHS=		aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON=	Cannot determine whether the target CPU is big or little endian - please fix PwsPlatform.h

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libxerces-c.so:textproc/xerces-c3 \
		libqrencode.so:graphics/libqrencode
BUILD_DEPENDS=	zip:archivers/zip

CONFLICTS=	pwsafe-[0-9]*

USES=		gmake xorg
USE_GITHUB=	yes
USE_WX=		3.0+
USE_XORG=	x11 xtst

OPTIONS_DEFINE=	NLS YUBIKEY
YUBIKEY_DESC=	Yubikey support
OPTIONS_SUB=	yes

NLS_USES=		gettext
YUBIKEY_LIB_DEPENDS=	libykpers-1.so:security/ykpers
YUBIKEY_MAKE_ENV_OFF=	NO_YUBI=yes

GH_ACCOUNT=	pwsafe
GH_PROJECT=	${GH_ACCOUNT}

WX_COMP=	wx
WANT_WX_VER=	3.0

LDFLAGS=	-L${PREFIX}/lib -lqrencode

ALL_TARGET=	unicoderelease

.include <bsd.port.options.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

post-patch:
.	for f in Makefile.freebsd help/Makefile.freebsd src/os/unix/Makefile \
		src/os/unix/dir.cpp src/ui/wxWidgets/pwsafeapp.cpp \
		src/ui/wxWidgets/Makefile
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
