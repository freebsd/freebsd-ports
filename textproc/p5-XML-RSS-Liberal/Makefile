# New ports collection makefile for:	p5-XML-RSS-Liberal
# Date created:		2006-07-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-Liberal
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	XML::RSS With A Liberal Parser

RUN_DEPENDS=	${SITE_PERL}/XML/Liberal.pm:${PORTSDIR}/textproc/p5-XML-Liberal	\
		${SITE_PERL}/XML/RSS/LibXML.pm:${PORTSDIR}/textproc/p5-XML-RSS-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::RSS::Liberal.3 XML::RSS::Liberal::Parser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703	# inherited from textprocs/p5-XML-RSS-LibXML
IGNORE=	requires perl 5.7.3 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
