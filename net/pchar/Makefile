# ex:ts=8
# Ports collection makefile for:  pchar
# Date created:			  Wed Nov 03, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	pchar
PORTVERSION=	1.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.kitchenlab.org/www/bmah/Software/pchar/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bmah

MAINTAINER=	bmah@FreeBSD.org
COMMENT=	Sandia Internet path characterization tool

GNU_CONFIGURE=	yes
MAN8=		pchar.8

.include <bsd.port.pre.mk>

CONFIGURE_ARGS= --with-pcap

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/pchar
	cd ${WRKSRC} ; ${INSTALL_DATA} README CHANGES FAQ ${PREFIX}/share/doc/pchar
.endif

.include <bsd.port.post.mk>
