# Created by: Bill Brinzer <bill.brinzer@gmail.com>
# $FreeBSD$

PORTNAME=	Email-Sender
PORTVERSION=	0.120001
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	A library for sending email

BUILD_DEPENDS=	p5-Email-Abstract>=3:${PORTSDIR}/mail/p5-Email-Abstract \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-Simple>=1.998:${PORTSDIR}/mail/p5-Email-Simple \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0.70:${PORTSDIR}/devel/p5-Moose \
		p5-Sys-Hostname-Long>=0:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-Throwable>=0.100090:${PORTSDIR}/devel/p5-Throwable
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Capture-Tiny>=0.08:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Sub-Override>=0:${PORTSDIR}/devel/p5-Sub-Override \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
