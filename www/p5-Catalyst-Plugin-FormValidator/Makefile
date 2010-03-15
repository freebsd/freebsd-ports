# New ports collection makefile for:	www/p5-Catalyst-Plugin-FormValidator
# Date created:				07 May 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-FormValidator
PORTVERSION=	0.094
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FormValidator for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.80001:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-FormValidator>=0:${PORTSDIR}/textproc/p5-Data-FormValidator \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::FormValidator.3

.include <bsd.port.mk>
