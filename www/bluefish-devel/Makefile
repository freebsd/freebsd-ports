# New ports collection makefile for:   bluefish
# Date created:			23 January 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	bluefish
PORTVERSION=	0.8.20030207
CATEGORIES=	www editors
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/snapshots/ \
		ftp://bluefish.advancecreations.com/pub/bluefish/snapshots/ \
		http://bluefish.mrball.net/snapshots/ \
		ftp://ftp.ratisbona.com/pub/bluefish/snapshots/ \
		http://bluefish.shellhung.org/snapshots/
DISTNAME=	${PORTNAME}-gtk2port-2003-02-07
EXTRACT_SUFX=	.tgz

MAINTAINER=	einekoai@chello.nl

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		pcre.0:${PORTSDIR}/devel/pcre \
		aspell.15:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint

WRKSRC=		${WRKDIR}/bluefish-gtk2
NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
