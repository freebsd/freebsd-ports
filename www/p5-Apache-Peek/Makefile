# New ports collection makefile for:	p5-Apache-Peek
# Date created:		24-Jul-2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Peek
PORTVERSION=	0.9501
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	leo@florida.sarang.net

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/B/Graph.pm:${PORTSDIR}/devel/p5-B-Graph

PERL_CONFIGURE=	YES

MAN3=		Apache::Peek.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
