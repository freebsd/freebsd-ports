# New ports collection makefile for:	Mail-Box
# Date created:				Wed Jan  3 12:54:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Box
PORTVERSION=	2.042
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module implementing a modern mail-folder managerat

BUILD_DEPENDS=	${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Object/Realize/Later.pm:${PORTSDIR}/devel/p5-Object-Realize-Later \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"This port requires perl 5.6 or newer.  Install lang/perl5 or lang/perl5.8 and try again."
.endif

MAN3=		\
		Mail::Box-Cookbook.3 \
		Mail::Box-Overview.3 \
		Mail::Box.3 \
		Mail::Box::Dbx.3 \
		Mail::Box::Dbx::Message.3 \
		Mail::Box::Dir.3 \
		Mail::Box::Dir::Message.3 \
		Mail::Box::File.3 \
		Mail::Box::File::Message.3 \
		Mail::Box::IMAP4.3 \
		Mail::Box::IMAP4::Message.3 \
		Mail::Box::Locker.3 \
		Mail::Box::Locker::DotLock.3 \
		Mail::Box::Locker::Flock.3 \
		Mail::Box::Locker::Multi.3 \
		Mail::Box::Locker::NFS.3 \
		Mail::Box::Locker::POSIX.3 \
		Mail::Box::MH.3 \
		Mail::Box::MH::Index.3 \
		Mail::Box::MH::Labels.3 \
		Mail::Box::MH::Message.3 \
		Mail::Box::Maildir.3 \
		Mail::Box::Maildir::Message.3 \
		Mail::Box::Manager.3 \
		Mail::Box::Mbox.3 \
		Mail::Box::Mbox::Message.3 \
		Mail::Box::Message.3 \
		Mail::Message::Head::Partial.3 \
		Mail::Box::Net.3 \
		Mail::Box::Net::Message.3 \
		Mail::Box::POP3.3 \
		Mail::Box::POP3::Message.3 \
		Mail::Box::Parser.3 \
		Mail::Box::Parser::Perl.3 \
		Mail::Box::Search.3 \
		Mail::Box::Search::Grep.3 \
		Mail::Box::Search::IMAP.3 \
		Mail::Box::Search::SpamAssassin.3 \
		Mail::Box::Thread::Manager.3 \
		Mail::Box::Thread::Node.3 \
		Mail::Box::Tie.3 \
		Mail::Box::Tie::ARRAY.3 \
		Mail::Box::Tie::HASH.3 \
		Mail::Message.3 \
		Mail::Message::Body.3 \
		Mail::Message::Body::Construct.3 \
		Mail::Message::Body::Delayed.3 \
		Mail::Message::Body::Encode.3 \
		Mail::Message::Body::File.3 \
		Mail::Message::Body::Lines.3 \
		Mail::Message::Body::Multipart.3 \
		Mail::Message::Body::Nested.3 \
		Mail::Message::Body::String.3 \
		Mail::Message::Construct.3 \
		Mail::Message::Construct::Bounce.3 \
		Mail::Message::Construct::Build.3 \
		Mail::Message::Construct::Forward.3 \
		Mail::Message::Construct::Read.3 \
		Mail::Message::Construct::Rebuild.3 \
		Mail::Message::Construct::Reply.3 \
		Mail::Message::Construct::Text.3 \
		Mail::Message::Convert.3 \
		Mail::Message::Convert::Html.3 \
		Mail::Message::Convert::HtmlFormatPS.3 \
		Mail::Message::Convert::HtmlFormatText.3 \
		Mail::Message::Convert::MailInternet.3 \
		Mail::Message::Convert::MimeEntity.3 \
		Mail::Message::Convert::TextAutoformat.3 \
		Mail::Message::Dummy.3 \
		Mail::Message::Field.3 \
		Mail::Message::Field::AddrGroup.3 \
		Mail::Message::Field::Address.3 \
		Mail::Message::Field::Addresses.3 \
		Mail::Message::Field::Attribute.3 \
		Mail::Message::Field::Fast.3 \
		Mail::Message::Field::Flex.3 \
		Mail::Message::Field::Full.3 \
		Mail::Message::Field::Unstructured.3 \
		Mail::Message::Head.3 \
		Mail::Message::Head::Complete.3 \
		Mail::Message::Head::Delayed.3 \
		Mail::Message::Head::ResentGroup.3 \
		Mail::Message::Head::Subset.3 \
		Mail::Message::Part.3 \
		Mail::Message::TransferEnc.3 \
		Mail::Message::TransferEnc::Base64.3 \
		Mail::Message::TransferEnc::Binary.3 \
		Mail::Message::TransferEnc::EightBit.3 \
		Mail::Message::TransferEnc::QuotedPrint.3 \
		Mail::Message::TransferEnc::SevenBit.3 \
		Mail::Message::Wrapper::SpamAssassin.3 \
		Mail::Reporter.3 \
		Mail::Transport.3 \
		Mail::Transport::Exim.3 \
		Mail::Transport::IMAP4.3 \
		Mail::Transport::Mailx.3 \
		Mail::Transport::POP3.3 \
		Mail::Transport::Qmail.3 \
		Mail::Transport::Receive.3 \
		Mail::Transport::SMTP.3 \
		Mail::Transport::Send.3 \
		Mail::Transport::Sendmail.3

.include <bsd.port.post.mk>
