# New ports collection makefile for:	p5-FastCGI
# Date created:				October 27th 1999
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	p5-FastCGI
PORTVERSION= 	0.48
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FCGI
DISTNAME=	FCGI-0.48

MAINTAINER=	kbyanc@posi.net

BUILD_DEPENDS=	${LOCALBASE}/lib/libfcgi.a:${PORTSDIR}/www/fcgi

USE_PERL5=	YES

MAN3=		FCGI.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL)

.include <bsd.port.mk>
