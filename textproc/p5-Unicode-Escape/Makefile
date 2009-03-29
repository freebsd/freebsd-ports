# New ports collection makefile for:	p5-Unicode-Escape
# Date created:				29 Mar 2009
# Whom:					Vadim Vatlin
#
# $FreeBSD$
#

PORTNAME=	Unicode-Escape
PORTVERSION=	0.0.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvatlin@masterhost.ru
COMMENT=	Escape and unescape Unicode characters other than ASCII

BUILD_DEPENDS=	p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Unicode::Escape.3

.include <bsd.port.mk>
