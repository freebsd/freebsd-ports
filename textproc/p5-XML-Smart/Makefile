# New ports collection makefile for:	p5-XML-Smart
# Date created:				October 10th 2000
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$

PORTNAME=	XML-Smart
PORTVERSION=	1.5.1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A Smart, easy and powerful way to access/create XML files/data

BUILD_DEPENDS=	${SITE_PERL}/Object/MultiType.pm:${PORTSDIR}/devel/p5-Object-MultiType \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		XML::Smart.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
