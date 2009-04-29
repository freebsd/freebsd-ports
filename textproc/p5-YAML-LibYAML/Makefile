# New ports collection makefile for:	p5-YAML-LibYAML
# Date created:		2009-04-28
# Whom:			TERAMOTO Masahiro <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	YAML-LibYAML
PORTVERSION=	0.32
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Perl YAML Serialization using XS and libyaml

BUILD_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		YAML::XS::LibYAML.3 \
		YAML::XS.3

.include <bsd.port.mk>
