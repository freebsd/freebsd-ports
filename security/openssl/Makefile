# New ports collection makefile for:	Eric Young's SSL/Crypto Library
# Version required:	0.6.5
# Date created:		1 July 1996
# Whom:			markm
#
# $Id: Makefile,v 1.8 1996/12/03 11:32:40 obrien Exp $
#

DISTNAME=		SSLeay-0.6.5
CATEGORIES=		devel security
MASTER_SITES=		ftp://psych.psy.uq.oz.au/pub/Crypto/SSL/

MAINTAINER=		markm@FreeBSD.ORG

RESTRICTED=		"Cryptography"
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	util/FreeBSD.sh
MAKEFILE=		Makefile.FreeBSD


post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SSLeay
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/SSLeay
.endif

.include <bsd.port.mk>
