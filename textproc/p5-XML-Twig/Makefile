# New ports collection makefile for:	p5-XML-Twig
# Date created:		13 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Twig
PORTVERSION=	3.09
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	Process huge XML documents by chunks via a tree interface

# On Perl < 5.8.0, XML::Twig has a further optional dependency on WeakRef.
# However, WeakRef needs Perl 5.005_55.
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	YES

MAN3=		XML::Twig.3

.include <bsd.port.mk>
