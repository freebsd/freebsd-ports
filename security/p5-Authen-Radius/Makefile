# New ports collection makefile for:    p5-Authen-Radius
# Date created:				September 11th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Authen-Radius
PORTVERSION=	0.05
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
DISTNAME=	RadiusPerl-0.05

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MD5.pm:${PORTSDIR}/security/p5-MD5

USE_PERL5=	YES
MAN3=		Authen::Radius.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
		@${CP} ${WRKSRC}/Authen/Radius.pm ${WRKSRC}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
