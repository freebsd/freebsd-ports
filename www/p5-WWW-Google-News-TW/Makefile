# New ports collection makefile for:	p5-WWW-Google-News
# Date created:		2006-07-17
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-Google-News-TW
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Access to Google's Taiwan News Service (Not Usenet)

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Google::News::TW.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800 # inherited from dependency upon utf8.pm
IGNORE=		requires perl 5.8 or above
.endif

.include <bsd.port.post.mk>
