# New ports collection makefile for:	pciutils
# Date created:				June 12, 2003
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	pciutils
PORTVERSION=	3.0.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		${MASTER_SITE_KERNEL_ORG} \
		ftp://metalab.unc.edu/pub/Linux/hardware/
MASTER_SITE_SUBDIR=	software/utils/pciutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PCI configuration utilities

USE_GMAKE=	yes

MAN8=		lspci.8 setpci.8 update-pciids.8

do-install:
	${INSTALL_MAN} ${WRKSRC}/lspci.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/setpci.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/update-pciids.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/lspci ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/setpci ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/update-pciids ${PREFIX}/sbin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${DATADIR}/pci.ids.sample

post-install:
	@if [ ! -f ${DATADIR}/pci.ids ]; then \
		${CP} -p ${DATADIR}/pci.ids.sample ${DATADIR}/pci.ids ; \
	fi

.include <bsd.port.mk>
