# New ports collection makefile for:	p5-WWW-Shorten-KUSO
# Date created:				2006-07-16
# Whom:					Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten-KUSO
PORTVERSION=	0.3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Shorten URL using http://KUSO.CC/

BUILD_DEPENDS=	${SITE_PERL}/WWW/Shorten.pm:${PORTSDIR}/www/p5-WWW-Shorten
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Shorten::KUSO.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our ([\$$\@]\w+)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use 5.006/;' \
		     -e '$$_ = "" if /use warnings/;' \
		 $$(${FIND} ${WRKSRC} -name '*.pm')
.endif

.include <bsd.port.post.mk>
