# New ports collection makefile for: naim
# Version required:     	0.9.3
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

DISTNAME=	naim-0.9.5-recon4
CATEGORIES=	net
MASTER_SITES=	http://dev.n.ml.org/ \
		ftp://ftp.netmug.org/pub/FreeBSD/distfiles/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	mharo@FreeBSD.org

GNU_CONFIGURE=	yes

#MAN1=		naim.1

post-install:
	@ ${MKDIR} ${PREFIX}/share/examples/naim
	@ ${INSTALL_DATA} ${WRKSRC}/doc/faimrc_sample ${PREFIX}/share/examples/naim/
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/naim
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naim.hlp ${PREFIX}/share/doc/naim/
.endif
	@ ${ECHO} "************************************************************"
	@ ${CAT} ${PKGDIR}/MESSAGE
	@ ${ECHO} "************************************************************"

.include <bsd.port.mk>
