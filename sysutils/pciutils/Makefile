# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	pciutils
PORTVERSION=	3.2.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PCI configuration utilities

LICENSE=	GPLv2

LIB_DEPENDS=	libpci.so:${PORTSDIR}/devel/libpci
RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:${PORTSDIR}/misc/pciids

ALL_TARGET=	lspci lspci.8 setpci setpci.8
CPPFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lpci
MAKE_ENV=	LANG=C
USES=		gmake

PLIST_FILES=	bin/lspci \
		bin/setpci \
		man/man8/lspci.8.gz \
		man/man8/setpci.8.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/d; /^CFLAGS=/ s|=|+=|; /^IDSDIR=/ s|$$|/pciids|; /^OPT=/d; /^PREFIX=/d; s| lib/$$(PCILIB)||' ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} lspci setpci ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_MAN} lspci.8 setpci.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
