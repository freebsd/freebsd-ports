#
# New ports collection makefile for:	nos-ttb
# Date created:				6 May 2005
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	nos-ttb
PORTVERSION=	0.9.1
CATEGORIES=	net
MASTER_SITES=	http://www.djcbsoftware.nl/code/ttb/
DISTNAME=	ttb
EXTRACT_SUFX=

MAINTAINER=	edwin@mavetju.org
COMMENT=	NOS teletekst browser

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PYTHON=	yes

PLIST_FILES=	bin/ttb

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
