# New ports collection makefile for: naim
# Version required:     	0.9.3
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $Id$
#

DISTNAME=	naim-0.9.3
CATEGORIES=	net
MASTER_SITES=	http://naim.n.ml.org/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mharo@area51.fremont.ca.us

GNU_CONFIGURE=	yes

MAN1=		naim.1

post-install:
	${ECHO} "Installing ${PREFIX}/share/examples/naim/faimrc_sample"
	${MKDIR} ${PREFIX}/share/examples/naim
	${INSTALL_DATA} ${WRKSRC}/doc/faimrc_sample ${PREFIX}/share/examples/naim/
	@${ECHO} "************************************************************"
	@${CAT} ${MASTERDIR}/pkg/MESSAGE
	@${ECHO} "************************************************************"

.include <bsd.port.mk>
