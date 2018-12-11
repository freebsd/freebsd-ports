# $FreeBSD$

PORTNAME=	isboot-kmod
PORTVERSION=	0.2.13
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/isboot/
DISTNAME=	isboot-${PORTVERSION}

MAINTAINER=	john@jnielsen.net
COMMENT=	Kernel module enabling iSCSI boot

LICENSE=	BSD2CLAUSE

BROKEN_aarch64=		fails to compile: /usr/src/sys/sys/bus.h:724:10: fatal error: 'device_if.h' file not found
BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99
BROKEN_armv7=		fails to compile: /usr/src/sys/sys/bus.h:724:10: fatal error: 'device_if.h' file not found

USES=		kmod uidfix
SUB_FILES=	pkg-message
WRKSRC_SUBDIR=	src
PLIST_FILES=	${KMODDIR}/isboot.ko
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS VIMAGE
VIMAGE_DESC=	Build for a kernel with 'options VIMAGE'
VIMAGE_CFLAGS=	-DVIMAGE

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
