# Created by: dikshie@lapi.itb.ac.id
# $FreeBSD$

PORTNAME=	ssmping
PORTVERSION=	0.9.1
PORTREVISION=	1
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800000
IGNORE=		does not work with FreeBSD 7.x
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ssmping ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/asmping ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/mcfirst ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/ssmpingd ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKSRC}/ssmping.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/asmping.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/mcfirst.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
