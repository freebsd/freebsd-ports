# ex:ts=8
# Ports collection makefile for:	XML::Parser::Lite::Tree
# Date created:			Apr 27, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	XML-Parser-Lite-Tree
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight XML tree builder

BUILD_DEPENDS=	${SITE_PERL}/XML/Parser/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Parser::Lite::Tree.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
