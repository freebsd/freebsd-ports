# New ports collection makefile for:	textproc/p5-Data-Phrasebook-Loader-YAML
# Date created:				05 May 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Phrasebook-Loader-YAML
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A loader class for phrasebook implementations using YAML

BUILD_DEPENDS=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Data-Phrasebook>=0:${PORTSDIR}/textproc/p5-Data-Phrasebook
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::Phrasebook::Loader::YAML.3

.include <bsd.port.mk>
