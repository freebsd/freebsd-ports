# New ports collection makefile for:	pciutils
# Date created:				June 12, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	pciutils
PORTVERSION=	2.1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kerneled.com/freebsd/ports/ \
		ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		ftp://ftp.kernel.org/pub/software/utils/pciutils/

MAINTAINER=	samy@kerneled.com
COMMENT=	PCI configuration utilities

USE_BZIP2=	yes
USE_GMAKE=	yes

MAN8=		lspci.8 setpci.8 update-pciids.8

pre-everything::
	@${ECHO} ""
	@${ECHO} "              W  A  R  N  I  N  G"
	@${ECHO} "************************************************"
	@${ECHO} "* pciutils requires that you have your kernel  *"
	@${ECHO} "* sources installed. If your kernel sources    *"
	@${ECHO} "* are somewhere other than /usr/src/sys, you   *"
	@${ECHO} "* may set the FREEBSD_SYS variable to the      *"
	@${ECHO} "* correct path.                                *"
	@${ECHO} "************************************************"
	@${ECHO} ""

do-install:
	@${INSTALL_MAN} ${WRKSRC}/lspci.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/setpci.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/update-pciids.8 ${PREFIX}/man/man8
	@${INSTALL_PROGRAM} ${WRKSRC}/lspci ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/setpci ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/update-pciids ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/pci.ids ${PREFIX}/share

.include <bsd.port.mk>
