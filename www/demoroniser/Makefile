# New ports collection makefile for:	demoroniser
# Date created:				07 August 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	demoroniser
PORTVERSION=	1.0.20030916
CATEGORIES=	www
MASTER_SITES=	http://www.fourmilab.ch/webtools/demoroniser/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jedgar
DISTNAME=	${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Correct moronic and gratuitously incompatible HTML from MS applications

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

MAN1=		demoroniser.1
PLIST_FILES=	bin/demoroniser

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/demoroniser.pl ${PREFIX}/bin/demoroniser
	${INSTALL_MAN} ${WRKDIR}/demoroniser.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
