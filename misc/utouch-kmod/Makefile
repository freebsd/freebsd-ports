PORTNAME=	utouch-kmod
PORTVERSION=	0.0.4
CATEGORIES=	misc

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Kernel driver for absolute USB HID mouses

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod uidfix

OPTIONS_DEFINE=	SOURCE
OPTIONS_DEFAULT=SOURCE
SOURCE_DESC=	Install kernel module sources

USE_GITHUB=	yes
GH_ACCOUNT=	wulf7
GH_PROJECT=	utouch

PLIST_FILES=	${KMODDIR}/utouch.ko

KMODSRC_DIR=	sys/modules/${PORTNAME}
KMODSRC_FILES=	Makefile utouch.c

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOURCE}
PLIST_FILES+=	${KMODSRC_FILES:S|^|${KMODSRC_DIR}/|}
.endif

post-install-SOURCE-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMODSRC_DIR}
.for file in ${KMODSRC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/${KMODSRC_DIR}
.endfor

.include <bsd.port.mk>
