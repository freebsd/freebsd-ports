# New ports collection makefile for:	p5-XML-LibXML-XPathContext
# Date created:				11 Sep 2003
# Whom:					Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML-XPathContext
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl interface to libxml2's xmlXPathContext

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::LibXML::XPathContext.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE="Need at least perl 5.6.1 to build"
.endif

.include <bsd.port.post.mk>
