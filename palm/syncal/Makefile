# New ports collection makefile for:    tclock
# Version required:     1.0.1
# Date created:		So   7 Feb 1999 20:50:43 MET
# Whom:			Lars Koeller <lkoeller@cc.fh-lippe.de>
#
# $FreeBSD$
#

DISTNAME=	syncal-0.5
CATEGORIES=	palm comms deskutils
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/	\
		http://www.daveltd.com/pilot/PalmOS/	\
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/

MAINTAINER=	Lars.Koeller@Uni-Bielefeled.DE

LIB_DEPENDS=	pisock:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS=	ical:${PORTSDIR}/deskutils/ical

NO_PACKAGE=	patches installed ical port

PREFIX=		${LOCALBASE}/pilot

MAN1=		syncal.1

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.patched
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" ${WRKSRC}/Makefile.patched > ${WRKSRC}/Makefile

#
# ical V2.2 needs a little patch, don't know how to do better
# perhaps the patch should be included int ical port by default
# Please have a look at this experts :-)
#
post-install:
	-cd ${LOCALBASE}/lib/ical/v2.2; \
	${PATCH} -f < ${WRKSRC}/ical.patch

.include <bsd.port.mk>
