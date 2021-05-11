PORTNAME=	isboot-kmod
PORTVERSION=	0.2.14
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/isboot/
DISTNAME=	isboot-${PORTVERSION}

MAINTAINER=	john@jnielsen.net
COMMENT=	Kernel module enabling iSCSI/IBFT boot

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	jnielsendotnet
GH_PROJECT=	isboot

SUB_FILES=	pkg-message
WRKSRC_SUBDIR=	src
PLIST_FILES=	${KMODDIR}/isboot.ko
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS VIMAGE
VIMAGE_DESC=	Build for a kernel with 'options VIMAGE'
VIMAGE_CFLAGS=	-DVIMAGE

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
