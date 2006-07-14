# New ports collection makefile for:	p5-Email-MIME
# Date created:				2004-08-29
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME
PORTVERSION=	1.85
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Easy MIME message parsing

BUILD_DEPENDS=	p5-Email-Simple>=1.91:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Email-MIME-Encodings>=1.3:${PORTSDIR}/mail/p5-Email-MIME-Encodings \
		p5-Email-MIME-ContentType>=1.0:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-MIME-Types>=1.13:${PORTSDIR}/mail/p5-MIME-Types
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::MIME.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	p5-MIME-Tools>=5.404:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS+=	p5-MIME-Tools>=5.404:${PORTSDIR}/mail/p5-MIME-Tools
.endif

.if ${PERL_LEVEL} < 500600
# inherited from mail/p5-MIME-Tools
IGNORE=		requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>
