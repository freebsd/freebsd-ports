# New ports collection makefile for:   p5-Net-MSN
# Date created:        22 June 2004
# Whom:                snowchyld
# $FreeBSD$

PORTNAME=	Net-MSN
PORTVERSION=	1.022
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	p5-net-msn-freebsd-ports@snowchyld.org
COMMENT=	Net::MSN interface

BUILD_DEPENDS=	${SITE_PERL}/Hash/Merge.pm:${PORTSDIR}/textproc/p5-Hash-Merge
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
