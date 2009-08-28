# New ports collection makefile for:	p5-Text-Flow
# Date created:				2008/08/30
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Text-Flow
DISTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible text flowing and word wrapping for not just ASCII output

RUN_DEPENDS=	p5-Moose>=0.45:${PORTSDIR}/devel/p5-Moose \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-LongString>=0:${PORTSDIR}/devel/p5-Test-LongString
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		${PORTNAME:S/-/::/g}.3 Text::Flow::Wrap.3

.include <bsd.port.mk>
