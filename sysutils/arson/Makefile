# New ports collection makefile for:	arson
# Date created:		22 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	arson
PORTVERSION=	0.9.5
CATEGORIES=	sysutils kde
MASTER_SITES=	http://belnet.dl.sourceforge.net/arson/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-kde3

MAINTAINER=	stefan.jahn@nemesis-sektor.de

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		bladeenc:${PORTSDIR}/audio/bladeenc

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
