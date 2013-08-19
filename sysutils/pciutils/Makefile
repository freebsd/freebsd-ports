# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	pciutils
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		KERNEL/software/utils/pciutils \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PCI configuration utilities

LICENSE=	GPLv2

LIB_DEPENDS=	pci:${PORTSDIR}/devel/libpci
RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:${PORTSDIR}/misc/pciids

ALL_TARGET=	${BINS} ${MAN8}
CPPFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lpci
MAKE_ENV=	LANG=C
USES=		gmake

BINS=		lspci setpci
MAN8=		lspci.8 setpci.8
PLIST_FILES=	${BINS:S/^/bin\//}

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/d; /^CFLAGS=/ s|=|+=|; /^IDSDIR=/ s|$$|/pciids|; /^OPT=/d; /^PREFIX=/d; s| lib/$$(PCILIB)||' ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC}/ && \
		${INSTALL_PROGRAM} ${BINS} ${PREFIX}/bin/ && \
		${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8/

.include <bsd.port.mk>
