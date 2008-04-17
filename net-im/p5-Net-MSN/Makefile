# New ports collection makefile for:   p5-Net-MSN
# Date created:        22 June 2004
# Whom:                snowchyld
# $FreeBSD$

PORTNAME=	Net-MSN
PORTVERSION=	1.022
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Net::MSN interface

BUILD_DEPENDS=	${SITE_PERL}/Hash/Merge.pm:${PORTSDIR}/textproc/p5-Hash-Merge
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
