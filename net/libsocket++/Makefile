# ex:ts=8
# Ports collection makefile for:  libsocket++
# Version required:     	  1.10
# Date created:			  Sun Jan 19, 1997
# Whom:				  Narvi <narvi@haldjas.folklore.ee>
#				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	socket++-1.10
PKGNAME=	libsocket++-1.10
CATEGORIES=     net
MASTER_SITES=	ftp://ftp.fh-furtwangen.de/pub/C++-class-libraries/networking/

MAINTAINER=	narvi@haldjas.folklore.ee

GNU_CONFIGURE=	yes
#NOPROFILE=	true

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
	@/sbin/ldconfig -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libsocket++
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/libsocket++
	${INSTALL_MAN} ${WRKSRC}/socket++.ps ${PREFIX}/share/doc/libsocket++
.endif

.include <bsd.port.mk>
