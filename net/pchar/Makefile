# ex:ts=8
# Ports collection makefile for:  pchar
# Version required:     	  1.0
# Date created:			  Wed Nov 03, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	pchar-1.0
CATEGORIES=	net
MASTER_SITES=	http://www.ca.sandia.gov/~bmah/Software/pchar/

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
MAN8=		pchar.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	@${PERL} -pi.orig -e 's/pchar 1/pchar 8/g' ${WRKSRC}/pchar.1
	${INSTALL_MAN} ${WRKSRC}/pchar.1 ${PREFIX}/man/man8/pchar.8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pchar
	cd ${WRKSRC} ; ${INSTALL_DATA} README FAQ ${PREFIX}/share/doc/pchar
.endif

.include <bsd.port.mk>
