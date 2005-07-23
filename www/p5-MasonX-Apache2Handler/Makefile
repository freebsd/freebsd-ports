# New ports collection makefile for:	www/p5-MasonX-Apache2Handler
# Date created:				June 5, 2004
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	MasonX-Apache2Handler
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MasonX
PKGNAMEPREFIX=	p5-

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Mason/mod_perl2 interface

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2/ModPerl/Config.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/${PERL_ARCH}/Apache2/Apache/Cookie.pm:${PORTSDIR}/www/p5-libapreq2 \
		${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

BROKEN=		Broken due the new mod_perl2 API
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

MAN3=		MasonX::Apache2Handler.3 MasonX::Mason-with-mod_perl2.3

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}

.include <bsd.port.mk>
