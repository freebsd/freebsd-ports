# New ports collection makefile for:   biffer
# Date created:        21 September 1999
# Whom:                jsellens
#
# $FreeBSD$
#

PORTNAME=	biffer
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.generalconcepts.com/resources/software/

MAINTAINER=	jsellens@generalconcepts.com
COMMENT=	A better mail notification server

RUN_DEPENDS=	xmsg:${PORTSDIR}/x11/xmsg

MAN1=		biffopt.1
MAN8=		biffer.8 biffer_comsat.8

do-install:
	${INSTALL_PROGRAM} \
	    ${WRKDIR}/${DISTNAME}/biffer/biffer ${PREFIX}/libexec
	${INSTALL_PROGRAM} \
	    ${WRKDIR}/${DISTNAME}/biffopt/biffopt ${PREFIX}/bin
	${INSTALL_MAN} \
	    ${WRKDIR}/${DISTNAME}/biffopt/biffopt.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} \
	    ${WRKDIR}/${DISTNAME}/biffer/biffer.8 ${MAN8PREFIX}/man/man8
	cd ${WRKDIR}/${DISTNAME}/biffer_comsat && ${MAKE} ${MFLAGS} install

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} \
	    POST-INSTALL

.include <bsd.port.mk>
