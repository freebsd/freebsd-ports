# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	demoroniser
PORTVERSION=	1.0.20030916
CATEGORIES=	www
MASTER_SITES=	http://www.fourmilab.ch/webtools/demoroniser/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jedgar
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Correct moronic and gratuitously incompatible HTML from MS applications

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

MAN1=		demoroniser.1
PLIST_FILES=	bin/demoroniser

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/demoroniser.pl ${PREFIX}/bin/demoroniser
	${INSTALL_MAN} ${WRKDIR}/demoroniser.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
