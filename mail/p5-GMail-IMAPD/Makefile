# New ports collection makefile for:	GMail-IMAPD
# Date created:				Jun 4, 2007
# Whom:					Ali Mashtizadeh <ali@mashtizadeh.org>
#
# $FreeBSD$
#

PORTNAME=	GMail-IMAPD
PORTVERSION=	0.94
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GMail
PKGNAMEPREFIX=	p5-

MAINTAINER=	mashtizadeh@gmail.com
COMMENT=	Perl IMAP4 gateway to Google's webmail service

BUILD_DEPENDS=	${SITE_PERL}/Mail/Webmail/Gmail.pm:${PORTSDIR}/mail/p5-Mail-Webmail-Gmail
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		GMail::IMAPD.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500601
	@${PERL} -pi -e 's/\r//g;s/^our/my/g' ${WRKSRC}/lib/GMail/IMAPD.pm
.endif

.include <bsd.port.post.mk>
