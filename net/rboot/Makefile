# New ports collection makefile for:    rboot
# Date created:         25 Jun 1999
# Whom:                 m.butkus@tu-bs.de
#
# $FreeBSD$
#

PORTNAME=	rboot
PORTVERSION=	3.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.bs.ni.schule.de/support/rboot/download/

MAINTAINER=	m.butkus@tu-bs.de
COMMENT=	A remote-boot solution for M$$ operating systems

NO_PACKAGE=	"this port creates devices"

MAN7=		rboot.7
MAN8=		netboot.8

.include <bsd.port.pre.mk>

post-install:
	@${ECHO} ""
	@${ECHO} "======================================================="
	@${ECHO} "This port performs only a basic RBoot installation."
	@${ECHO} "Please see the file ${WRKDIR}/${DISTNAME}/INSTALL"
	@${ECHO} "for additional instructions on setting up RBoot."
	@${ECHO} "Note that RBoot has been installed in ${PREFIX}/rboot."
	@${ECHO} "======================================================="
	@${ECHO} ""

.include <bsd.port.post.mk>
