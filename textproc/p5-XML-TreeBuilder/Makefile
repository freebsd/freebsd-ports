# New ports collection makefile for:	XML-TreeBuilder
# Date created:				Tue Jan  2 00:03:51 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	XML-TreeBuilder
PORTVERSION=	3.09
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to make XML document trees

BUILD_DEPENDS=	${SITE_PERL}/HTML/Tree.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::TreeBuilder.3 XML::Element.3

.include <bsd.port.mk>
