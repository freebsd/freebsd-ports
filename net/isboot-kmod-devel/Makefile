PORTNAME=	isboot-kmod
DISTVERSION=	0.2.16-beta1
CATEGORIES=	net
PKGNAMESUFFIX=	-devel

MAINTAINER=	john@jnielsen.net
COMMENT=	Kernel module enabling iSCSI/IBFT boot
WWW=		https://github.com/jnielsendotnet/isboot

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS_INSTALL= isboot-kmod

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	jnielsendotnet
GH_PROJECT=	isboot

SUB_FILES=	pkg-message

WRKSRC_SUBDIR=	src

PLIST_FILES=	${KMODDIR}/isboot.ko
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS VIMAGE
OPTIONS_DEFAULT=DOCS VIMAGE

VIMAGE_DESC=	Build for a kernel with 'options VIMAGE'

VIMAGE_CFLAGS=	-DVIMAGE

.include <bsd.port.options.mk>

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
