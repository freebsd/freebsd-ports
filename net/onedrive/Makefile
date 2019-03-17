# $FreeBSD$

PORTNAME=	onedrive
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
CATEGORIES=	net

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	Microsoft OneDrive client

LICENSE=	GPLv3

BUILD_DEPENDS=	ldmd2:lang/ldc
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify

USES=		sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	skilion

OPTIONS_DEFAULT=	LDC
OPTIONS_SINGLE=		DLANG
OPTIONS_SINGLE_DLANG=	DMD1 DMD2 LDC

DMD1_DESC=	Use lang/dmd1 as D compiler
DMD2_DESC=	Use lang/dmd2 as D compiler
LDC_DESC=	Use lang/ldc as D compiler

DMD1_MAKE_ARGS=	DC=dmd1
DMD2_MAKE_ARGS=	DC=dmd
LDC_MAKE_ARGS=	DC=ldmd2

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${FILESDIR}/freebsd_inotify.d ${WRKSRC}/src
	${CP} ${FILESDIR}/version ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/onedrive ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
