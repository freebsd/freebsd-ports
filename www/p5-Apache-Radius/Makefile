# New ports collection makefile for:	p5-Apache-Radius
# Date created:				Mon 20 Sep 19:46:21 SAST 1999
# Whom:					Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Radius
PORTVERSION=	0.3
CATEGORIES=	www security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-
DISTNAME=	Apache-AuthenRadius-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 module for providing RADIUS authentication in Apache+mod_perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/Authen/Radius.pm:${PORTSDIR}/security/p5-Authen-Radius
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthenRadius.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
