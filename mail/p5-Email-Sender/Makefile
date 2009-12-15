# New ports collection makefile for:	mail/p5-Email-Sender
# Date created:				23 June 2009
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Email-Sender
PORTVERSION=	0.093380
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	A library for sending email

BUILD_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Email-Abstract>=3:${PORTSDIR}/mail/p5-Email-Abstract \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-Simple>=1.998:${PORTSDIR}/mail/p5-Email-Simple \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Sys-Hostname-Long>=0:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long
RUN_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Email-Abstract>=3:${PORTSDIR}/mail/p5-Email-Abstract \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-Simple>=1.998:${PORTSDIR}/mail/p5-Email-Simple \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Sys-Hostname-Long>=0:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long

PERL_CONFIGURE=	5.8.1+

MAN3=	Email::Sender.3 \
	Email::Sender::Failure.3 \
	Email::Sender::Failure::Multi.3 \
	Email::Sender::Failure::Permanent.3 \
	Email::Sender::Failure::Temporary.3 \
	Email::Sender::Manual.3 \
	Email::Sender::Manual::QuickStart.3 \
	Email::Sender::Role::CommonSending.3 \
	Email::Sender::Role::HasMessage.3 \
	Email::Sender::Simple.3 \
	Email::Sender::Success.3 \
	Email::Sender::Success::Partial.3 \
	Email::Sender::Transport.3 \
	Email::Sender::Transport::DevNull.3 \
	Email::Sender::Transport::Failable.3 \
	Email::Sender::Transport::Maildir.3 \
	Email::Sender::Transport::Mbox.3 \
	Email::Sender::Transport::Print.3 \
	Email::Sender::Transport::SMTP.3 \
	Email::Sender::Transport::SMTP::Persistent.3 \
	Email::Sender::Transport::Sendmail.3 \
	Email::Sender::Transport::Test.3 \
	Email::Sender::Transport::Wrapper.3 \
	Email::Sender::Util.3

.include <bsd.port.mk>
