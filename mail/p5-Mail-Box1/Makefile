# New ports collection makefile for:	Mail-Box
# Date created:				Wed Jan  3 12:54:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Box
PORTVERSION=	0.4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500007
BROKEN=		"Requires Perl 5.6.0 for 'our' keyword"
.endif

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::Box.3 Mail::Box::Tie.3 Mail::Box::Mbox.3 \
		Mail::Box::MH.3 Mail::Box::Manager.3 \
		Mail::Box::Message.3 Mail::Box::Threads.3 \
		Mail::Box::Locker.3 Mail::Box::Index.3

.include <bsd.port.post.mk>
