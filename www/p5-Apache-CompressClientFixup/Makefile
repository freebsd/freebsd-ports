# New ports collection makefile for:	Apache::CompressClientFixup
# Date created:				25 May 2004
# Whom:					Bill Swingle <unfurl@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-CompressClientFixup
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	unfurl@FreeBSD.org
COMMENT=	Perl extension for Apache-1.3.X to avoid gzip compression for known buggy browsers

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/Constants.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::CompressClientFixup.3

.include <bsd.port.mk>
