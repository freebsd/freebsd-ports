# New ports collection makefile for:	textproc/p5-XML-DTDParser
# Date created:				Oct 13th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$

PORTNAME=	XML-DTDParser
PORTVERSION=	2.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -pi -e 's/^our ([^\s;]+)/use vars qw($$1); $$1/;' \
		     ${WRKSRC}/DTDParser.pm
.endif

.include <bsd.port.post.mk>
