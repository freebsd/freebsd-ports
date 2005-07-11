# New ports collection makefile for:	Jacal
# Date created:				Sat Mar 16 2002
# Whom:					Mark R V Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jacal
PORTVERSION=	1b5
CATEGORIES=	math
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
DISTNAME=	jacal1b5

MAINTAINER=	markm@FreeBSD.org
COMMENT=	Symbolic mathematics program written in Scheme

RUN_DEPENDS=	scm:${PORTSDIR}/lang/scm

WRKSRC=		${WRKDIR}/jacal

USE_ZIP=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		jacal.1

do-configure:
	cd ${WRKSRC}; \
	${FIND} . -type f -exec perl -spi -e 's|%%PREFIX%%|${PREFIX}|' {} ';'

.include <bsd.port.mk>
