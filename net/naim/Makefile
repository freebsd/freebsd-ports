# New ports collection makefile for: naim
# Version required:     	0.9.3
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $Id: Makefile,v 1.2 1999/04/16 09:19:46 mharo Exp $
#

DISTNAME=	naim-0.9.3
CATEGORIES=	net
MASTER_SITES=	http://naim.n.ml.org/release/ \
		ftp://ftp.netmug.org/pub/FreeBSD/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mharo@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=		naim.1

post-install:
	${ECHO} "Installing ${PREFIX}/share/examples/naim/faimrc_sample"
	${MKDIR} ${PREFIX}/share/examples/naim
	${INSTALL_DATA} ${WRKSRC}/doc/faimrc_sample ${PREFIX}/share/examples/naim/
	@${ECHO} "************************************************************"
	@${CAT} ${PKGDIR}/MESSAGE
	@${ECHO} "************************************************************"

.include <bsd.port.mk>
