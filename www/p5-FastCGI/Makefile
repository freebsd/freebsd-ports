# New ports collection makefile for:	p5-FastCGI
# Date created:				October 27th 1999
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	FastCGI
PORTVERSION=	0.71
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	FCGI
PKGNAMEPREFIX=	p5-
DISTNAME=	FCGI-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules for perl5, for enabling FastCGI support in CGI scripts

# XXX: fcgi.0 is missing FCGX_Detach, see ports/149755
#LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi
#CONFIGURE_ARGS+=	--use-installed=${LOCALBASE}

PERL_CONFIGURE=	yes
MAKE_ARGS=	CCFLAGS="${CFLAGS}"

MAN3=		FCGI.3

.include <bsd.port.mk>
