# New ports collection makefile for:	p5-Apache-Radius
# Version required:			0.3
# Date created:				Mon 20 Sep 19:46:21 SAST 1999
# Whom:					Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Apache-AuthenRadius-0.3
PKGNAME=	p5-Apache-Radius-0.3
CATEGORIES=	www security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache

MAINTAINER=	sheldonh@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Authen/Radius.pm:${PORTSDIR}/security/p5-Authen-Radius

USE_PERL5=	YES

MAN3=		Apache::AuthenRadius.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
