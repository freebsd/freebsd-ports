# New ports collection makefile for:	p5-AuthCAS
# Date created:			Mon Jul 20 17:25:19 CEST 2009
# Whom:				Frank Wall <fw@moov.de>
#
# $FreeBSD$
#

PORTNAME=	AuthCAS
PORTVERSION=	1.5
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OSALAUN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	A Perl API to Yale's Central Authentication System (CAS)

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL

RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		AuthCAS.3

.include <bsd.port.mk>
