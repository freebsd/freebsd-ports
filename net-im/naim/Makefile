# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.11.2
CATEGORIES=	net
MASTER_SITES=	http://dev.n.ml.org/ \
		ftp://ftp.netmug.org/pub/FreeBSD/distfiles/

MAINTAINER=	mharo@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
	@ ${MKDIR} ${PREFIX}/share/examples/naim
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naimrc_sample ${PREFIX}/share/examples/naim/
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/naim
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naim.hlp ${PREFIX}/share/doc/naim/
.endif
	@ ${ECHO} "************************************************************"
	@ ${CAT} ${PKGMESSAGE}
	@ ${ECHO} "************************************************************"

.include <bsd.port.mk>
