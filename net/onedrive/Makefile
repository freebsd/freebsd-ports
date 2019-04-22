# $FreeBSD$

PORTNAME=	onedrive
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	Microsoft OneDrive client

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify
BUILD_DEPENDS=	ldc2:lang/ldc

USES=		sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	skilion

MAKE_ARGS=	DC=ldc2

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
