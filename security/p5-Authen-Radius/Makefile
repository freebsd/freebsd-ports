# New ports collection makefile for:    p5-Authen-Radius
# Version required:			0.05
# Date created:				September 11th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1998/09/15 21:31:52 asami Exp $
#

DISTNAME=	RadiusPerl-0.05
PKGNAME=	p5-Authen-Radius-0.05
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/MD5.pm:${PORTSDIR}/security/p5-MD5
USE_PERL5=	YES

MAN3=		Authen::Radius.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
		@${CP} ${WRKSRC}/Authen/Radius.pm ${WRKSRC}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
