# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.10.1
CATEGORIES=	net
MASTER_SITES=	http://dev.n.ml.org/ \
		ftp://ftp.netmug.org/pub/FreeBSD/distfiles/

MAINTAINER=	mharo@FreeBSD.org

GNU_CONFIGURE=	yes

# Manpage is empty
#MAN1=		naim.1

post-install:
	@ ${RM} ${PREFIX}/man/man1/naim.1
	@ ${MKDIR} ${PREFIX}/share/examples/naim
	@ ${INSTALL_DATA} ${WRKSRC}/doc/faimrc_sample ${PREFIX}/share/examples/naim/
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/naim
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naim.hlp ${PREFIX}/share/doc/naim/
.endif
	@ ${ECHO} "************************************************************"
	@ ${CAT} ${PKGMESSAGE}
	@ ${ECHO} "************************************************************"

.include <bsd.port.mk>
