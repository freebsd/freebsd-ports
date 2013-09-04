# New ports collection makefile for:	mail/p5-Email-Valid-Loose
# Date created:		19 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Valid-Loose
PORTVERSION=	0.05
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A variation of Email::Valid which allows dot before at mark

BUILD_DEPENDS=	p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Email::Valid::Loose.3

.include <bsd.port.mk>
