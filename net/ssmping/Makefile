# New ports collection makefile for:  ssmping
# Date created:		20 August 2006
# Whom:			dikshie@lapi.itb.ac.id
#
# $FreeBSD$
#

PORTNAME=	ssmping
PORTVERSION=	0.9.1
CATEGORIES=	net
MASTER_SITES=	http://www.venaas.no/multicast/ssmping/

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	Ping for ASM and SSM

MAN1=		ssmping.1 \
		asmping.1 \
		mcfirst.1

PLIST_FILES=	bin/ssmping \
		bin/asmping \
		bin/mcfirst \
		sbin/ssmpingd

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ssmping ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/asmping ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/mcfirst ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/ssmpingd ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKSRC}/ssmping.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/asmping.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/mcfirst.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
