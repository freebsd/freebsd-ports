# Created by: Lapo Luchini <lapo@lapo.it>
# $FreeBSD$

PORTNAME=	tagzilla
PORTVERSION=	0.066.2
CATEGORIES=	www
MASTER_SITES=	http://downloads.mozdev.org/xsidebar/mods/
# Origin: http://forums.mozillazine.org/viewtopic.php?p=8467965#p8467965

MAINTAINER=	lapo@lapo.it
COMMENT=	Lets you add a tagline to the end of an email or newsgroup posting

RUN_DEPENDS=	${LOCALBASE}/lib/xpi/{DF8E5247-8E0A-4de6-B393-0735A39DFD80}/install.rdf:www/xpi-jslib

LICENSE=	MPL # also "GPL" but doesn't specify version and doesn't contain license text

XPI_ID=		{4eac6fec-f68b-4797-be7a-ffeea73e1495}
XPI_FILES=	chrome/tagzilla.jar chrome.manifest components/tzprefs-service.js \
		defaults/preferences/tagzilla_prefs.js install.js install.rdf \
		release-notes.txt translator.credits.txt
XPI_DIRS=	chrome components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
