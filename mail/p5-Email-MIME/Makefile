# New ports collection makefile for:	p5-Email-MIME
# Date created:				2004-08-29
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME
PORTVERSION=	1.82
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Easy MIME message parsing

BUILD_DEPENDS=	${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple \
		${SITE_PERL}/Email/MIME/Encodings.pm:${PORTSDIR}/mail/p5-Email-MIME-Encodings \
		${SITE_PERL}/Email/MIME/ContentType.pm:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::MIME.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	${SITE_PERL}/MIME/Words.pm:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS+=	${SITE_PERL}/MIME/Words.pm:${PORTSDIR}/mail/p5-MIME-Tools
.endif

.if ${PERL_LEVEL} <= 500503
post-patch:
	${PERL} -pi -e '$$_ = "" if /require 5.006;/;' \
		    -e '$$_ = "" if /use warnings/;' \
		    -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/MIME.pm
.endif

.include <bsd.port.post.mk>
