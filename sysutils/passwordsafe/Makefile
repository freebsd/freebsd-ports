# $FreeBSD$

PORTNAME=	passwordsafe
DISTVERSION=	1.02BETA
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Popular secure and convenient password manager

LICENSE=	ART20

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libxerces-c.so:textproc/xerces-c3
BUILD_DEPENDS=	zip:archivers/zip

NOT_FOR_ARCHS=		aarch64 armv6
NOT_FOR_ARCHS_REASON=	Cannot determine whether the target CPU is big or little endian - please fix PwsPlatform.h

CONFLICTS=	pwsafe-[0-9]*

USES=		gmake
USE_GITHUB=	yes
USE_WX=		3.0+
USE_XORG=	x11 xtst

GH_ACCOUNT=	pwsafe
GH_PROJECT=	${GH_ACCOUNT}

WX_COMP=	wx
WANT_WX_VER=	3.0

ALL_TARGET=	unicoderelease

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

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

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
BROKEN=	clang segfaults on 10.x
.endif

.include <bsd.port.post.mk>
