# New ports collection makefile for:	pciutils
# Date created:				June 12, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	pciutils
PORTVERSION=	2.1.11
PORTREVISION=	1
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
	@${ECHO_MSG} ""
	@${ECHO_MSG} "              W  A  R  N  I  N  G"
	@${ECHO_MSG} "************************************************"
	@${ECHO_MSG} "* pciutils requires that you have your kernel  *"
	@${ECHO_MSG} "* sources installed. If your kernel sources    *"
	@${ECHO_MSG} "* are somewhere other than /usr/src/sys, you   *"
	@${ECHO_MSG} "* may set the FREEBSD_SYS variable to the      *"
	@${ECHO_MSG} "* correct path.                                *"
	@${ECHO_MSG} "************************************************"
	@${ECHO_MSG} ""

do-install:
	@${INSTALL_MAN} ${WRKSRC}/lspci.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/setpci.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/update-pciids.8 ${PREFIX}/man/man8
	@${INSTALL_PROGRAM} ${WRKSRC}/lspci ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/setpci ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/update-pciids ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/pci.ids ${PREFIX}/share

.include <bsd.port.mk>
