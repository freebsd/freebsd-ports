# New ports collection makefile for:	p5-Email-Sender-Transport-SQLite
# Date created:				11 Oct 2010
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Email-Sender-Transport-SQLite
PORTVERSION=	0.091660
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Deliver mail to an SQLite db for testing

RUN_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Email-Sender>=0.091660:${PORTSDIR}/mail/p5-Email-Sender
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.8+

MAN3=		Email::Sender::Transport::SQLite.3

.include <bsd.port.mk>
