# New ports collection makefile for:	tkrunnit
# Date created:			6 February, 1999
# Whom:				Stephen Farrell <steve@farrell.org>
#
# $FreeBSD$
#

PORTNAME=	tkRunIt
PORTVERSION=	0.94.1
CATEGORIES=	misc
MASTER_SITES=   http://www.cs.columbia.edu/~etgold/software/tkRunIt/
DISTNAME=	tkRunIt-0941

MAINTAINER=	steve@farrell.org
COMMENT=	GUI app launcher with completion and history

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes

post-extract:
	@(cd ${WRKDIR} ; ${MV} tkRunIt ${DISTNAME})

do-install:
	@(cd ${WRKSRC} ; ${INSTALL_SCRIPT} runit.tcl ${PREFIX}/bin)

post-install:
	@${ECHO} "		"
	@${ECHO} "-------------------------------------------------------------------"
	@${ECHO} "===> Installing runitrc.sample in ${PREFIX}/share/examples/tkrunit"
	@${ECHO} "===> Copy runitrc.sample to ~/.runitrc and modify if you wish"
	@${ECHO} "-------------------------------------------------------------------"
	@${ECHO} "		"
	@${MKDIR} ${PREFIX}/share/examples/tkrunit && ${CHMOD} a+rx ${PREFIX}/share/examples/tkrunit
	@${INSTALL_DATA} ${WRKSRC}/runitrc.sample ${PREFIX}/share/examples/tkrunit

.include <bsd.port.mk>
