# New ports collection makefile for:	p5-FastCGI-ProcManager
# Date created:			18 January 2004
# Whom:				Scott McWhirter <scott@surreytech.co.uk>
#
# $FreeBSD$
#

PORTNAME=	FastCGI-ProcManager
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	FCGI
PKGNAMEPREFIX=	p5-
DISTNAME=	FCGI-ProcManager-${PORTVERSION}

MAINTAINER=	scott@surreytech.co.uk
COMMENT=	Functions for managing FastCGI applications

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		FCGI::ProcManager.3

.include <bsd.port.mk>
