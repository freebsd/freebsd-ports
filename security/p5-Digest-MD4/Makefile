# ex:ts=8
# Ports collection makefile for:	p5-Digest-MD4
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Digest-MD4
PORTVERSION=	1.5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl5 interface to the MD4 message digest algorithm

PERL_CONFIGURE=	yes

MAN3=		Digest::MD4.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes rfc1320.txt

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
