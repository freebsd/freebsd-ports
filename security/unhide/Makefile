# New ports collection makefile for:   unhide
# Date created:        26 February 2009
# Whom:                ntarmos@cs.uoi.gr
#
# $FreeBSD$
#

PORTNAME=	unhide
PORTVERSION=	20080519
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.security-projects.com/
DISTNAME=	${PORTNAME}${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	A forensic tool to find hidden processes and TCP/UDP ports

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
PLIST_FILES=	sbin/unhide sbin/unhide-tcp
MAN8=		unhide.8 unhide-tcp.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's/-eLf/-axH/g' -e 's/$$2/$$1/g' ${WRKSRC}/unhide.c
	@${REINPLACE_CMD} -e 's/-t/-p tcp -/g' -e 's/-u/-p udp -/g' \
		${WRKSRC}/unhide-tcp.c

.include <bsd.port.post.mk>
