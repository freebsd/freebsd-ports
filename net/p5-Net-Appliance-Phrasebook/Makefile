# New ports collection makefile for:	net/p5-Net-Appliance-Phrasebook
# Date created:				05 May 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Appliance-Phrasebook
PORTVERSION=	1.8
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Network appliance command-line phrasebook

BUILD_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		${SITE_PERL}/Data/Phrasebook.pm:${PORTSDIR}/textproc/p5-Data-Phrasebook \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Data/Phrasebook/Loader/YAML.pm:${PORTSDIR}/textproc/p5-Data-Phrasebook-Loader-YAML \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Appliance::Phrasebook.3

.include <bsd.port.mk>
