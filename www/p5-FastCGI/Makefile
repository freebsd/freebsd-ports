# New ports collection makefile for:	p5-FastCGI
# Version required:			0.48
# Date created:				October 27th 1999
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

DISTNAME=	FCGI-0.48
PKGNAME=	p5-FastCGI-0.48
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FCGI

MAINTAINER=	kbyanc@posi.net

BUILD_DEPENDS=	${PREFIX}/lib/libfcgi.a:${PORTSDIR}/www/fcgi

USE_PERL5=	YES

MAN3=		FCGI.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL)

.include <bsd.port.mk>
