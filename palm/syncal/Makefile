# New ports collection makefile for:    syncal
# Date created:		So   7 Feb 1999 20:50:43 MET
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	syncal
PORTVERSION=	0.8.9
CATEGORIES=	palm comms deskutils
MASTER_SITES=	http://hopf.math.nwu.edu/syncal/ \
		ftp://ftp.Uni-Bielefeld.DE/pub/systems/FreeBSD/lkoeller/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Synchronize your PalmPilot with ical

LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS=	ical:${PORTSDIR}/deskutils/ical

NO_PACKAGE=	patches installed ical port

MAN1=		syncal.1

post-patch:
.for file in Makefile user.tcl ical.patch
	${REINPLACE_CMD} -e "s|\@\@PREFIX\@\@|${LOCALBASE}|g" ${WRKSRC}/${file}
.endfor

# ical V2.2 needs a little patch, don't know how to do better
# perhaps the patch should be included int ical port by default
# Please have a look at this experts :-)
#
post-install:
	-cd ${LOCALBASE}/lib/ical/v2.2; \
	${PATCH} -f < ${WRKSRC}/ical.patch

.include <bsd.port.mk>
