# New ports collection makefile for:	p5-Email-LocalDelivery
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-LocalDelivery
PORTVERSION=	0.09
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Deliver a piece of email - simply

BUILD_DEPENDS=	${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple \
		${SITE_PERL}/Email/FolderType.pm:${PORTSDIR}/mail/p5-Email-FolderType \
		${SITE_PERL}/File/Path/Expand.pm:${PORTSDIR}/devel/p5-File-Path-Expand
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::LocalDelivery.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600

EXTRA_PATCHES=	${FILESDIR}/5.005-LocalDelivery::Mbox.pm

post-patch:
	@${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/LocalDelivery.pm \
		${WRKSRC}/LocalDelivery/Maildir.pm \
		${WRKSRC}/LocalDelivery/Mbox.pm
	@${RM} ${WRKSRC}/LocalDelivery/Mbox.pm.orig

.endif

.include <bsd.port.post.mk>
