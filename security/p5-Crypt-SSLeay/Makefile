# New ports collection makefile for:	p5-Crypt-SSLeay
# Date created:				December-15-2000
# Whom:	      				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-SSLeay
PORTVERSION=	0.51
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl5 interface to allow p5-libwww LWP to make https connections

BUILD_DEPENDS=		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	"/usr"
USE_OPENSSL=	yes

MAN3=		Crypt::SSLeay.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
