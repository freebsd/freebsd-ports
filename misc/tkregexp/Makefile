# New ports collection makefile for:	tklregexp
# Date created:        2 May 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	tkregexp
PORTVERSION=	2.1
CATEGORIES=	misc tk83
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/
DISTNAME=	visual_regexp-${PORTVERSION}

MAINTAINER=	patseal@hyperhost.net

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
NO_BUILD=   yes
USE_X_PREFIX=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp-${PORTVERSION}.tcl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
