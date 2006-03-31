# New ports collection makefile for:	mail/p5-Mail-MboxParser
# Date created:				31 March 2006
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-MboxParser
PORTVERSION=	0.55
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A module for working with UNIX-flavoured mailboxes

BUILD_DEPENDS=	${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}//${PERL_ARCH}/MIME/QuotedPrint.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Mail/Mbox/MessageParser.pm:${PORTSDIR}/mail/p5-Mail-Mbox-MessageParser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::MboxParser.3 \ Mail::MboxParser::Base.3 \
		Mail::MboxParser::Mail.3 \
		Mail::MboxParser::Mail::Body.3 \
		Mail::MboxParser::Mail::Convertable.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
