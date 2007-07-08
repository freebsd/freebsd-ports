# New ports collection makefile for:	Catalyst-View-ClearSilver
# Date created:	   08 July 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-ClearSilver
PORTVERSION=	0.01
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	ClearSilver view class for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/ClearSilver.pm:${PORTSDIR}/www/p5-ClearSilver \
		p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Helper::View::ClearSilver.3 \
		Catalyst::View::ClearSilver.3

.include <bsd.port.mk>
