# New ports collection makefile for:	mail/p5-Net-IMAP-Server
# Date created:				December 18, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IMAP-Server
PORTVERSION=	1.26
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A single-threaded multiplexing IMAP server implementation

BUILD_DEPENDS=	p5-Net-Server-Coro>=0.6:${PORTSDIR}/net/p5-Net-Server-Coro \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-Encode-IMAPUTF7>=0:${PORTSDIR}/converters/p5-Encode-IMAPUTF7 \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Email-MIME>=0:${PORTSDIR}/mail/p5-Email-MIME
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::IMAP::Server.3 \
	Net::IMAP::Server::Command.3 \
	Net::IMAP::Server::Connection.3 \
	Net::IMAP::Server::DefaultAuth.3 \
	Net::IMAP::Server::DefaultModel.3 \
	Net::IMAP::Server::Error.3 \
	Net::IMAP::Server::Mailbox.3 \
	Net::IMAP::Server::Message.3

.include <bsd.port.mk>
