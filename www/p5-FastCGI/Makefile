# New ports collection makefile for:	p5-FastCGI
# Date created:				October 27th 1999
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	FastCGI
PORTVERSION= 	0.52
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FCGI
DISTNAME=	FCGI-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	kbyanc@posi.net

BUILD_DEPENDS=	${LOCALBASE}/lib/libfcgi.a:${PORTSDIR}/www/fcgi

USE_PERL5=	yes

MAN3=		FCGI.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
