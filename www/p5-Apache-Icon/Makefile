# New ports collection makefile for:	Apache-Icon
# Date created:				Mon Jan  1 04:09:18 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-Icon
PORTVERSION=	0.02
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl module that provides an interface for looking up icon images

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

MAN3=		Apache::Icon.3

.include <bsd.port.mk>
