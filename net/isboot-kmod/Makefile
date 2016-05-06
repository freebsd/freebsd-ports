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
	cd ${WRKDIR}/${DISTNAME} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
