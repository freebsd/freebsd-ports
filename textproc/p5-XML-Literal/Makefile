# New ports collection makefile for:	p5-XML-Literal
# Date created:		2006-08-01
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Literal
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Syntax support for XML literals

RUN_DEPENDS=	p5-Sub-Override>=0:${PORTSDIR}/devel/p5-Sub-Override
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Literal.3

.include <bsd.port.mk>
