# New ports collection makefile for:	Mail-Webmail-Gmail
# Date created:				Jul 25 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Mail-Webmail-Gmail
PORTVERSION=	1.04
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to Google webmail service

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Webmail::Gmail.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500601
	@${PERL} -pi -e 's/\r//g;s/^our/my/g' ${WRKSRC}/lib/Mail/Webmail/Gmail.pm
.endif

.include <bsd.port.post.mk>
