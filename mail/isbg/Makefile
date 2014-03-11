# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

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

RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/spamassassin

DISTDATE=	20100303
NO_BUILD=	yes
USE_PYTHON=	yes

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/isbg.py ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
