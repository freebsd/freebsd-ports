# New ports collection makefile for:	fluxbox-fluxmod
# Date created:		01.09.2004
# Whom:			Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	fluxbox-fluxmod
PORTVERSION=	20040825
CATEGORIES=	x11-themes
MASTER_SITES=	http://ikaro.dk/e107_files/downloads/
DISTNAME=	fluxbox-styles-fluxmod-${PORTVERSION}

MAINTAINER=	sam@brj.pp.ru
COMMENT=	Ikaro.dk themes pack for fluxbox

RUN_DEPENDS=	fluxbox:${PORTSDIR}/x11-wm/fluxbox-devel

CONFLICTS=	flux-art-*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
.for i in ACiD Alien Alien-Neptune Azure Bawn Blood-Integration Blue CBlue \
Calabi Cinza CityOfDreams Fire-Eye-II Gentoo GleamFlux Granite \
Graphite-Integration Green-Tubes Greenstone Harddriven Klassix Klassix-Green \
Klassix-Red Lait Magraxx Mercxx Nuevat3k-Glacier OSX-Graphite Onyx2 Overflow \
Panbox Perl Siro Sith-II Sn33z SuKIT Tiger WildBugs XP-Green Yopsyra \
addicted2blue addicted2blue102 deepblue lingo platinium pr0n sea snow
	${CP} -R ${WRKDIR}/styles/${i} ${PREFIX}/share/fluxbox/styles/
.endfor

.include <bsd.port.mk>
