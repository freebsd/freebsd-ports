# Ports collection makefile for:  ipv6toolkit
# Date created:			  Mon, July 16, 2012
# Whom:				  hrs
#
# $FreeBSD$
#

PORTNAME=	ipv6toolkit
PORTVERSION=	1.2.2
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.si6networks.com/research/
DISTNAME=	ipv6-toolkit-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A set of IPv6 security assessment tools

LICENSE=	GPLv3

.if !defined(NOPORTDOCS)
MAKE_ENV=	WITH_DOCS=
MAN1=		scan6.1
.endif

PORTDOCS=	README.TXT flow6-manual.pdf frag6-manual.pdf		\
		icmp6-manual.pdf jumbo6-manual.pdf na6-manual.pdf	\
		ni6-manual.pdf ns6-manual.pdf ra6-manual.pdf		\
		rd6-manual.pdf rs6-manual.pdf scan6-manual.pdf		\
		tcp6-manual.pdf

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
