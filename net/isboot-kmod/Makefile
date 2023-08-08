PORTNAME=	isboot-kmod
DISTVERSION=	0.2.14
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	john@jnielsen.net
COMMENT=	Kernel module enabling iSCSI/IBFT boot
WWW=		https://github.com/jnielsendotnet/isboot

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

OPTIONS_DEFINE=	DEBUG DOCS VIMAGE
OPTIONS_DEFAULT=DOCS VIMAGE

DEBUG_DESC=	Enable verbose boot logging
VIMAGE_DESC=	Build for a kernel with 'options VIMAGE'

DEBUG_CFLAGS=	-DDEBUG -DMODDEBUG -DIBFT_VERBOSE
VIMAGE_CFLAGS=	-DVIMAGE

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
