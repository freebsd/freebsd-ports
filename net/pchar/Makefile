# ex:ts=8
# Ports collection makefile for:  pchar
# Date created:			  Wed Nov 03, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	pchar
PORTVERSION=	1.3.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.employees.org/~bmah/Software/pchar/

MAINTAINER=	bmah@FreeBSD.org

GNU_CONFIGURE=	yes
MAN8=		pchar.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS= --with-ipv6
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/pchar
	cd ${WRKSRC} ; ${INSTALL_DATA} README CHANGES FAQ ${PREFIX}/share/doc/pchar
.endif

.include <bsd.port.post.mk>
