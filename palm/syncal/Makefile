# New ports collection makefile for:    syncal
# Date created:		So   7 Feb 1999 20:50:43 MET
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	syncal
PORTVERSION=	0.8.6
CATEGORIES=	palm comms deskutils
MASTER_SITES=	http://hopf.math.nwu.edu/syncal/ \
		ftp://ftp.Uni-Bielefeld.DE/pub/systems/FreeBSD/lkoeller/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS=	ical:${PORTSDIR}/deskutils/ical

NO_PACKAGE=	patches installed ical port

PREFIX=		${LOCALBASE}/pilot

MAN1=		syncal.1

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.patched
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" ${WRKSRC}/Makefile.patched > ${WRKSRC}/Makefile
	${MV} ${WRKSRC}/user.tcl ${WRKSRC}/user.tcl.patched
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" ${WRKSRC}/user.tcl.patched > ${WRKSRC}/user.tcl
	${MV} ${WRKSRC}/ical.patch ${WRKSRC}/ical.patch.patched
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" ${WRKSRC}/ical.patch.patched > ${WRKSRC}/ical.patch

#
# ical V2.2 needs a little patch, don't know how to do better
# perhaps the patch should be included int ical port by default
# Please have a look at this experts :-)
#
post-install:
	-cd ${LOCALBASE}/lib/ical/v2.2; \
	${PATCH} -f < ${WRKSRC}/ical.patch

.include <bsd.port.mk>
