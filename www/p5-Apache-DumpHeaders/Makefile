# New ports collection makefile for:    p5-Apache-DumpHeaders
# Date created:				2002-05-31
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Apache-DumpHeaders
PORTVERSION=	0.94
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

MAN3=		Apache::DumpHeaders.3 Apache::ProxyPassThru.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
