# New ports collection makefile for:	p5-Net-SSH-Expect
# Date created:		2007-06-30
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-SSH-Expect
PORTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SSH wrapper to execute remote commands

RUN_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::SSH::Expect.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 due to dependency. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
