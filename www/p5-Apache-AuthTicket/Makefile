# New ports collection makefile for:	Apache-AuthTicket
# Date created:				Sun Dec 31 19:57:53 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthTicket
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Apache/AuthCookie.pm:${PORTSDIR}/www/p5-Apache-AuthCookie
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::AuthTicket.3

.include <bsd.port.mk>
