# New ports collection makefile for:	tklregexp
# Date created:        2 May 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	tkregexp
PORTVERSION=	3.0
CATEGORIES=	misc tk83
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/
DISTNAME=	visual_regexp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive regexp design tool

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/tkregexp
USE_X_PREFIX=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}/visual_regexp.tcl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
