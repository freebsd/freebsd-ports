# New ports collection makefile for:	mail/p5-Mail-Mbox-MessageParser
# Date created:				Oct 28 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Mail-Mbox-MessageParser
PORTVERSION=	1.20
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A fast and simple mbox folder reader

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/FileHandle/Unget.pm:${PORTSDIR}/devel/p5-FileHandle-Unget
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Mbox::MessageParser.3 \
		Mail::Mbox::MessageParser::Cache.3 \
		Mail::Mbox::MessageParser::Grep.3 \
		Mail::Mbox::MessageParser::Perl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
