# New ports collection makefile for:	p5-Email-MIME-Attachment-Stripper
# Date created:				2004-08-30
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-Attachment-Stripper
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Strip the attachments from a mail

BUILD_DEPENDS=	${SITE_PERL}/Email/MIME.pm:${PORTSDIR}/mail/p5-Email-MIME \
		${SITE_PERL}/Email/MIME/ContentType.pm:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		${SITE_PERL}/Email/MIME/Modifier.pm:${PORTSDIR}/mail/p5-Email-MIME-Modifier
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::MIME::Attachment::Stripper.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/lib/Email/MIME/Attachment/Stripper.pm
	${PERL} -pi -e '$$_ = "" if (/use warnings/);' \
		${WRKSRC}/Makefile.PL \
		${WRKSRC}/t/01.t \
		${WRKSRC}/lib/Email/MIME/Attachment/Stripper.pm
.endif

.include <bsd.port.post.mk>
