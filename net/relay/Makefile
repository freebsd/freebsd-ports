# ex:ts=8
# Ports collection makefile for:  relay
# Version required:     	  1.10
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	relay
PKGNAME=	relay-1.10
CATEGORIES=	net security
MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/  \
		http://www.freebsd.org/~obrien/Distfiles/

MAINTAINER=     obrien@FreeBSD.org

IS_INTERACTIVE=	'must set server hostname in relay.h'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/relay ${PREFIX}/libexec
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} rtelnet rftp rfinger ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/relay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/relay
.endif

.include <bsd.port.mk>
