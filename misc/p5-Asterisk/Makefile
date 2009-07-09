# New ports collection makefile for:	p5-Asterisk
# Date created:				11 October 2004
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=		Asterisk
PORTVERSION=	1.01
CATEGORIES=		misc perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-
DISTNAME=		asterisk-perl-${PORTVERSION}

MAINTAINER=		perl@FreeBSD.org
COMMENT=		Asterisk perl library

PERL_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/asterisk-perl-${PORTVERSION}

MAN3=			Asterisk::Manager.3 Asterisk::Voicemail.3 \
				Asterisk::Outgoing.3 Asterisk::AGI.3

.include <bsd.port.mk>
