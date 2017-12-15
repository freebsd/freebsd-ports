# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	pciutils
PORTVERSION=	3.5.6
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/software/utils/pciutils \
		ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PCI configuration utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpci.so:devel/libpci
RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids

ALL_TARGET=	lspci lspci.8 setpci setpci.8
CFLAGS+=	-fPIC
LDFLAGS+=	-lpci
USES=		gmake localbase:ldflags tar:xz

PLIST_FILES=	bin/lspci \
		bin/setpci \
		man/man8/lspci.8.gz \
		man/man8/setpci.8.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/d; /^CFLAGS=/ s|=|+=|; /^IDSDIR=/ s|$$|/pciids|; /^OPT=/d; /^PREFIX=/d; s| lib/$$(PCILIB)||' ${WRKSRC}/Makefile

do-configure:
	${CP} ${LOCALBASE}/include/pci/config.h ${WRKSRC}/lib/config.h
	${CP} ${LOCALBASE}/share/libpci/config.mk ${WRKSRC}/lib/config.mk

do-install:
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} lspci setpci ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_MAN} lspci.8 setpci.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
