# New ports collection makefile for:	Tree-Authz
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tree-Authz
PORTVERSION=	0.03
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Role-Based Access Control authorization scheme

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/Inflect/Number.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Tree::Authz.3 Tree::Authz::Role.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
