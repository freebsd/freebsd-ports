# New ports collection makefile for:	Math::SimpleVariable
# Date created:		5 Nov 2001
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SimpleVariable
PORTVERSION=	0.03
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Simple representation of mathematical variables

BUILD_DEPENDS=	${SITE_PERL}/fields.pm:${PORTSDIR}/devel/p5-Class-Fields
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::SimpleVariable.3

pre-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | ${XARGS} ${PERL} -pi -e \
		'$$package=$$1 if /^package\s+([^\s;]*);/; s!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+(\$$)(VERSION)\s+=!$$1$${package}::$$2=!;'

.include <bsd.port.mk>
