# New ports collection makefile for:	p5-Apache-Radius
# Date created:				Mon 20 Sep 19:46:21 SAST 1999
# Whom:					Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Radius
PORTVERSION= 	0.3
CATEGORIES=	www security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
DISTNAME=	Apache-AuthenRadius-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	sheldonh@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Authen/Radius.pm:${PORTSDIR}/security/p5-Authen-Radius
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes

MAN3=		Apache::AuthenRadius.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
