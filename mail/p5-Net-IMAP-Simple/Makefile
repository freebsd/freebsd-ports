# New ports collection makefile for:	mail/p5-Net-IMAP-Simple
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IMAP-Simple
PORTVERSION=	1.2019
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN/../by-authors/id/J/JE/JETTERO
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension for simple IMAP account handling

PERL_CONFIGURE=	yes

MAN3=		Net::IMAP::Simple.3 \
		Net::IMAP::Simple::PipeSocket.3

OPTIONS=	SX "Simple protocol extensions (use Parse::RecDescent)" off

.include <bsd.port.options.mk>

CONFIGURE_ENV+=	WITH_SX="${WITH_SX}"

.include <bsd.port.pre.mk>

.ifdef(WITH_SX)
PLIST_SUB+=	WITH_SX=""
MAN3+=		Net::IMAP::SimpleX.3
RUN_DEPENDS+=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
.else
PLIST_SUB+=	WITH_SX="@comment "
.endif

.include <bsd.port.post.mk>
