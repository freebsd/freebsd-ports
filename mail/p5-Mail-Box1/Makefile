# New ports collection makefile for:	Mail-Box
# Date created:				Wed Jan  3 12:54:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Box
PORTVERSION=	1.324
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module implementing a modern mail-folder managerat

BUILD_DEPENDS=	${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_LATEST_LINK=	yes
PERL_CONFIGURE=	yes

MAN3=		Mail::Box.3 \
		Mail::Box::Index.3 \
		Mail::Box::Locker.3 \
		Mail::Box::MH.3 \
		Mail::Box::MH::Message.3 \
		Mail::Box::Manager.3 \
		Mail::Box::Mbox.3 \
		Mail::Box::Mbox::Message.3 \
		Mail::Box::Message.3 \
		Mail::Box::Threads.3 \
		Mail::Box::Tie.3 \
		Mail::Box::Tie::ARRAY.3 \
		Mail::Box::Tie::HASH.3 \
		Mail::Message.3

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@]\w+)/use vars qw($$1);$$1/' \
		${WRKSRC}/Message.pm

.include <bsd.port.mk>
