# New ports collection makefile for:	p5-CGI
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI
PORTVERSION= 	2.76
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
DISTNAME=	CGI-modules-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS= 	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes

MAN3=		CGI::Base.3 CGI::BasePlus.3 CGI::Carp.3 CGI::Form.3 \
		CGI::MiniSvr.3 CGI::Request.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
