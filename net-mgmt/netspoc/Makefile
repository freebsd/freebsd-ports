# ex:ts=8
# Ports collection makefile for:	netspoc
# Date created:			Nov 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netspoc
PORTVERSION=	1.7
CATEGORIES=	net-mgmt
MASTER_SITES=	http://download.berlios.de/netspoc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Network Security Policy Compiler

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		netspoc.1
DOCS=		*.html

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"This port needs Perl 5.6.0 or greater"
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netspoc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Netspoc.pm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/netspoc.man ${MANPREFIX}/man/man1/netspoc.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
