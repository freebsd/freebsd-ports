# New ports collection makefile for:	p5-FastCGI
# Date created:				October 27th 1999
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	FastCGI
PORTVERSION=	0.67
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FCGI
PKGNAMEPREFIX=	p5-
DISTNAME=	FCGI-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modules for perl5, for enabling FastCGI support in CGI scripts

LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--use-installed=${LOCALBASE}
MAKE_ARGS=	CCFLAGS="${CFLAGS}"

MAN3=		FCGI.3

.include <bsd.port.mk>
