# New ports collection makefile for:	Catalyst-View-ClearSilver
# Date created:	   08 July 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-ClearSilver
PORTVERSION=	0.02
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JR/JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	ClearSilver view class for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/ClearSilver.pm:${PORTSDIR}/www/p5-ClearSilver \
		p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/${PERL_ARCH}/Data/Structure/Util.pm:${PORTSDIR}/devel/p5-Data-Structure-Util \
		${SITE_PERL}/Class/C3.pm:${PORTSDIR}/devel/p5-Class-C3 \
		${SITE_PERL}/Catalyst/View/Templated.pm:${PORTSDIR}/www/p5-Catalyst-View-Templated
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Helper::View::ClearSilver.3 \
		Catalyst::View::ClearSilver.3

.include <bsd.port.mk>
