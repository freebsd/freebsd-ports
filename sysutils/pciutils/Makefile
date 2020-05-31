# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	pciutils
PORTVERSION=	3.7.0
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/software/utils/pciutils \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PCI configuration utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libpci>=${PORTVERSION}:devel/libpci
LIB_DEPENDS=	libpci.so:devel/libpci
RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids

USES=		gmake localbase:ldflags tar:xz

ALL_TARGET=	lspci lspci.8 setpci setpci.8
CFLAGS+=	-fPIC
LDFLAGS+=	-lpci

PLIST_FILES=	bin/lspci \
		bin/setpci \
		share/man/man8/lspci.8.gz \
		share/man/man8/setpci.8.gz

do-configure:
	${CP} ${LOCALBASE}/include/pci/config.h ${WRKSRC}/lib/config.h
	${CP} ${LOCALBASE}/share/libpci/config.mk ${WRKSRC}/lib/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lspci ${WRKSRC}/setpci ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/lspci.8 ${WRKSRC}/setpci.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
