# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-SimpleVariable
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple representation of mathematical variables

USES=		perl5
USE_PERL5=	configure patch

pre-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | ${XARGS} ${PERL} -pi -e \
		'$$package=$$1 if /^package\s+([^\s;]*);/; s!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+(\$$)(VERSION)\s+=!$$1$${package}::$$2=!;'

.include <bsd.port.mk>
