# New ports collection makefile for:   bluefish
# Date created:			23 January 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	bluefish
PORTVERSION=	0.8.20030113
CATEGORIES=	www editors
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/snapshots/ \
		ftp://bluefish.advancecreations.com/pub/bluefish/snapshots/ \
		http://bluefish.mrball.net/snapshots/ \
		ftp://ftp.ratisbona.com/pub/bluefish/snapshots/ \
		http://bluefish.shellhung.org/snapshots/
DISTNAME=	${PORTNAME}-gtk2port-2003-01-13
EXTRACT_SUFX=	.tgz

MAINTAINER=	einekoai@chello.nl

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint

WRKSRC=		${WRKDIR}/bluefish-gtk2
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
