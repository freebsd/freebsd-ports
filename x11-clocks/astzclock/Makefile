# New ports collection makefile for:   astzclock
# Date created:        3 August 2004
# Whom:                Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	astzclock
PORTVERSION=	1.0
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	http://www.eyesbeyond.com/freebsddom/astzclock/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Afterstep clock with some timezone extensions

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		astzclock.1
PLIST_FILES=	bin/astzclock

pre-configure:
	(cd ${WRKSRC}; \
	${ECHO_CMD} ${ASCLOCK_LANG} | ${WRKSRC}/configure > /dev/null)
	@${ECHO_MSG} "*****************  NOTE  *****************"
	@${ECHO_MSG} "*                                        *"
	@${ECHO_MSG} "*  You can choose languages for asclock. *"
	@${ECHO_MSG} "* 1) engligh [DEFAULT]                   *"
	@${ECHO_MSG} "* 2) german                              *"
	@${ECHO_MSG} "* 3) portuguese                          *"
	@${ECHO_MSG} "* 4) dutch                               *"
	@${ECHO_MSG} "* 5) norwegian                           *"
	@${ECHO_MSG} "* 6) italian                             *"
	@${ECHO_MSG} "* 7) swedish                             *"
	@${ECHO_MSG} "* 8) spanish                             *"
	@${ECHO_MSG} "* 9) hungarian                           *"
	@${ECHO_MSG} "* 0) breton                              *"
	@${ECHO_MSG} "* a) french                              *"
	@${ECHO_MSG} "* b) czech                               *"
	@${ECHO_MSG} "*                                        *"
	@${ECHO_MSG} "* Specify the number you want when make. *"
	@${ECHO_MSG} "* Example: \" make ASCLOCK_LANG=1 \"       *"
	@${ECHO_MSG} "******************************************"

.include <bsd.port.mk>
