# New ports collection makefile for:	www/p5-Catalyst-Component-ACCEPT_CONTEXT
# Date created:				26 April 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Component-ACCEPT_CONTEXT
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Make the Catalyst request context available in Models and Views

RUN_DEPENDS=	p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Component::ACCEPT_CONTEXT.3

post-patch:
	${PERL} -pi -e '$$_="" if /auto_install|Devel::Cycle/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
