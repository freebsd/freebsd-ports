# New ports collection makefile for:	p5-XML-XPathEngine
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XPathEngine
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A re-usable XPath engine for DOM-like trees

PERL_CONFIGURE=	yes

MAN3=		XML::XPathEngine.3 XML::XPathEngine::Boolean.3 \
		XML::XPathEngine::Literal.3 XML::XPathEngine::NodeSet.3 \
		XML::XPathEngine::Number.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/extra-*

post-patch:
	${PERL} -pi -e '$$_ = "" if /^use warnings/' ${WRKSRC}/Makefile.PL
	${FIND} ${WRKSRC} -name '*.orig' -delete
.endif

.include <bsd.port.post.mk>
