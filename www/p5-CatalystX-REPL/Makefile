# New ports collection makefile for:	p5-CatalystX-REPL
# Date created:		2011-05-08
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CatalystX-REPL
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read-Eval-Print-Loop for debugging your Catalyst application

BUILD_DEPENDS=	p5-Carp-REPL>=0:${PORTSDIR}/devel/p5-Carp-REPL \
		p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-Carp-REPL>=0:${PORTSDIR}/devel/p5-Carp-REPL \
		p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=		CatalystX::REPL.3

.include <bsd.port.mk>
