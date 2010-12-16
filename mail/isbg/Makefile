# New ports collection makefile for:	isbg
# Date created:		2010-01-28
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	isbg
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cloud.github.com/downloads/ook/isbg/ \
		http://home.bluelife.at/ports/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}_${DISTDATE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Scan an IMAP inbox for spam using SpamAssassin

RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin

DISTDATE=	20100303
NO_BUILD=	yes
USE_PYTHON=	2.5+

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/isbg.py ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
