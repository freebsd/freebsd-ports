# New ports collection makefile for:	p5-HTTPD-Tools
# Version required:			0.55
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	HTTPD-Tools-0.55
PKGNAME=	p5-HTTPD-Tools-0.55
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTPD

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		HTTPD::Authen.3 HTTPD::UserAdmin.3 HTTPD::GroupAdmin.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
