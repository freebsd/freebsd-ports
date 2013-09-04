# New ports collection makefile for:	mail/p5-Mail-MboxParser
# Date created:				31 March 2006
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-MboxParser
PORTVERSION=	0.55
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A module for working with UNIX-flavoured mailboxes

BUILD_DEPENDS=	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Mail-Mbox-MessageParser>=0:${PORTSDIR}/mail/p5-Mail-Mbox-MessageParser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Mail::MboxParser.3 Mail::MboxParser::Base.3 \
		Mail::MboxParser::Mail.3 \
		Mail::MboxParser::Mail::Body.3 \
		Mail::MboxParser::Mail::Convertable.3

.include <bsd.port.mk>
