# New ports collection makefile for:	biblical-curse
# Date created:		08 Nov 2005
# Whom:			Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	biblical-curse
PORTVERSION=	0.02
CATEGORIES=	misc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fake biblical curse generator

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/src
USE_PERL5_RUN=	yes

SRC=		${.CURDIR}/src

do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/biblical-curse

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/biblical-curse ${PREFIX}/bin/biblical-curse

.include <bsd.port.mk>
