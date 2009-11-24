# New ports collection makefile for:	p5-Parse-BooleanLogic
# Date created:		2009-11-23
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-BooleanLogic
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Parser of boolean expressions

BUILD_DEPENDS=	p5-Regexp-Common>=2.122:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Module-Install>=0.91_1:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Parse::BooleanLogic.3

.include <bsd.port.mk>
