# New ports collection makefile for:	mail/p5-Email-MessageID
# Date created:				27 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MessageID
PORTVERSION=	1.31
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Generate world unique message-ids

BUILD_DEPENDS=	${SITE_PERL}/Email/Address.pm:${PORTSDIR}/mail/p5-Email-Address
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::MessageID.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
EXTRA_PATCHES=	${FILESDIR}/5.005-Makefile.PL
.endif
.include <bsd.port.post.mk>
