# New ports collection makefile for:	pciutils
# Date created:				June 12, 2003
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	pciutils
PORTVERSION=	2.2.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		ftp://ftp.kernel.org/pub/software/utils/pciutils/ \
		ftp://metalab.unc.edu/pub/Linux/hardware/

MAINTAINER=	sbahra@gwu.edu
COMMENT=	PCI configuration utilities

USE_GMAKE=	yes
MAKE_ENV=	LANG=C

MAN8=		lspci.8 setpci.8 update-pciids.8

do-install:
	@${INSTALL_MAN} ${WRKSRC}/lspci.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/setpci.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/update-pciids.8 ${PREFIX}/man/man8
	@${INSTALL_PROGRAM} ${WRKSRC}/lspci ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/setpci ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/update-pciids ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/pci.ids ${PREFIX}/share

.include <bsd.port.mk>
