# New ports collection makefile for:	p5-FastCGI
# Date created:				October 27th 1999
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	FastCGI
PORTVERSION=	0.58
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FCGI
PKGNAMEPREFIX=	p5-
DISTNAME=	FCGI-${PORTVERSION}

MAINTAINER=	kbyanc@posi.net

BUILD_DEPENDS=	${LOCALBASE}/lib/libfcgi.a:${PORTSDIR}/www/fcgi

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		FCGI.3

.include <bsd.port.mk>
