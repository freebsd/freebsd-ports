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
COMMENT=	A perl5 data debugging tool for the XS programmer

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/B/Graph.pm:${PORTSDIR}/devel/p5-B-Graph

PERL_CONFIGURE=	YES

MAN3=		Apache::Peek.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

.include <bsd.port.post.mk>
