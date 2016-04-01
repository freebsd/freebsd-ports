# Created by: David Gardner
# $FreeBSD$

PORTNAME=	gkrelltop
PORTVERSION=	2.2.13
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for gkrellm 2.x shows top three processes, requires procfs

LICENSE=	GPLv2

BUILD_DEPENDS=	gkrellmd:sysutils/gkrellm2
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USES=		gmake pkgconfig
MAKE_ARGS=	CC="${CC} ${CFLAGS} $$(pkg-config gtk+-2.0 --cflags)" \
		CCD="${CC} ${CFLAGS} $$(pkg-config glib-2.0 --cflags)" \
		INSTALLDIR=${PREFIX}/libexec/gkrellm2/plugins \
		INSTALLDIRD=${PREFIX}/libexec/gkrellm2/plugins-gkrellmd

CFLAGS+=	-fPIC -DFREEBSD -DGKRELLM2

PLIST_FILES=	libexec/gkrellm2/plugins-gkrellmd/gkrelltopd.so

.if defined(GKRELLM_SERVER_ONLY)
ALL_TARGET=	server
.else
PLIST_FILES+=	libexec/gkrellm2/plugins/gkrelltop.so
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins-gkrellmd
	(cd ${WRKSRC} && ${INSTALL_LIB} gkrelltopd.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins-gkrellmd)
.if !defined(GKRELLM_SERVER_ONLY)
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	(cd ${WRKSRC} && ${INSTALL_LIB} gkrelltop.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins)
.endif

.include <bsd.port.mk>
