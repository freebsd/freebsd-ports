# New ports collection makefile for:   mcl
# Date created:        29 October 2003
# Whom:                past@noc.ntua.gr
#
# $FreeBSD$
#

PORTNAME=	mcl
PORTVERSION=	2.99
CATEGORIES=	mbone net
MASTER_SITES=	http://www.inrialpes.fr/planete/people/roca/mcl/bin/
DISTNAME=	mcl_v2.99
EXTRACT_SUFX=	.tgz

MAINTAINER=	past@noc.ntua.gr
COMMENT=	Implementation of the ALC and NORM Reliable Multicast Protocols

USE_GMAKE=	yes
MAN1=		fcast.1 fcastn.1 mclrecv2.1 mclsend2.1
MAN2=		mcl_abort.2 mcl_close.2 mcl_ctl.2 mcl_open.2 mcl_recv.2 \
		mcl_send.2 mcl_wait_event.2
WRKSRC=		${WRKDIR}/mcl_v2.99_src

pre-patch:
	@cd ${WRKSRC} &&  \
		${MKDIR} bin/freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/freebsd/fcast ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/freebsd/robcast_client ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/freebsd/robcast_server ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/freebsd/libmclalc.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/fcast.man.1 ${PREFIX}/man/man1/fcast.1
	${INSTALL_MAN} ${WRKSRC}/man/fcastn.man.1 ${PREFIX}/man/man1/fcastn.1
	${INSTALL_MAN} ${WRKSRC}/man/mclrecv2.man.1 \
		${PREFIX}/man/man1/mclrecv2.1
	${INSTALL_MAN} ${WRKSRC}/man/mclsend2.man.1 \
		${PREFIX}/man/man1/mclsend2.1
	${INSTALL_MAN} ${WRKSRC}/man/mcl_abort.man.2 \
		${PREFIX}/man/man2/mcl_abort.2
	${INSTALL_MAN} ${WRKSRC}/man/mcl_close.man.2 \
		${PREFIX}/man/man2/mcl_close.2
	${INSTALL_MAN} ${WRKSRC}/man/mcl_ctl.man.2 ${PREFIX}/man/man2/mcl_ctl.2
	${INSTALL_MAN} ${WRKSRC}/man/mcl_open.man.2 \
		${PREFIX}/man/man2/mcl_open.2
	${INSTALL_MAN} ${WRKSRC}/man/mcl_recv.man.2 \
		${PREFIX}/man/man2/mcl_recv.2
	${INSTALL_MAN} ${WRKSRC}/man/mcl_send.man.2 \
		${PREFIX}/man/man2/mcl_send.2
	${INSTALL_MAN} ${WRKSRC}/man/mcl_wait_event.man.2 \
		${PREFIX}/man/man2/mcl_wait_event.2

.include <bsd.port.mk>
