# New ports collection makefile for:	Apache-AuthenURL
# Date created:				Sun Dec 31 20:08:48 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthenURL
PORTVERSION=	0.9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache/mod_perl module to handle auth against external URLs

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Apache/AuthenCache.pm:${PORTSDIR}/www/p5-Apache-AuthenCache
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthenURL.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

.include <bsd.port.mk>
