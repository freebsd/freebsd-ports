# New ports collection makefile for:    ipex
# Date created:         5 January 2002
# Whom:                 C.S. Peron <maneo@bsdpro.com>
#
# $FreeBSD$
#

PORTNAME=	ipex
PORTVERSION=	2.3.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ipex

MAINTAINER=	maneo@bsdpro.com

MAN1=		ipex.1
MANCOMPRESSED=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ipex-HOWTO.pdf ipex-HOWTO.txt pcap_exprs.txt regexps.txt rfc0768.txt rfc0792.txt rfc0793.txt
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
