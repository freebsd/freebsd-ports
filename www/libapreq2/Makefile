# New ports collection makefile for:	p5-libapreq2
# Date created:				June 5, 2004
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	libapreq2
PORTVERSION=	2.02r02
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=libapreq
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/_/}-dev

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Generic Apache2 Request Library

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/ExtUtils/XSBuilder:${PORTSDIR}/devel/p5-ExtUtils-XSBuilder \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2:${PORTSDIR}/www/mod_perl2

CONFLICTS=	p5-libapreq

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-perl-glue
USE_PERL5=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME:S/_02//}

MAN3=		Apache::Cookie.3 Apache::Request.3

.include <bsd.port.mk>
