# New ports collection makefile for:	mail/p5-Email-Valid-Loose
# Date created:		19 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Valid-Loose
PORTVERSION=	0.04
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A variation of Email::Valid which allows dot before at mark

BUILD_DEPENDS=	${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Valid::Loose.3

.include <bsd.port.mk>
