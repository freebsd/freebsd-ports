# New ports collection makefile for:    p5-Apache-SSI
# Date created:				May 27 2001
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	Apache-SSI
PORTVERSION=	2.16
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/SimpleParse.pm:${PORTSDIR}/www/p5-HTML-SimpleParse
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::SSI.3

.include <bsd.port.mk>
