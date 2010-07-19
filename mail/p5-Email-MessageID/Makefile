# New ports collection makefile for:	mail/p5-Email-MessageID
# Date created:				27 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MessageID
PORTVERSION=	1.402
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate world unique message-ids

RUN_DEPENDS=	p5-Email-Address>=1.80:${PORTSDIR}/mail/p5-Email-Address
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::MessageID.3

.include <bsd.port.mk>
