# New ports collection makefile for:	textproc/p5-XML-DTDParser
# Date created:				Oct 13th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$

PORTNAME=	XML-DTDParser
PORTVERSION=	2.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for parsing XML DTD strings

PERL_CONFIGURE=	yes

MAN3=		XML::DTDParser.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
