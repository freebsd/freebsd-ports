# New ports collection makefile for:	p5-Apache-ASP
# Date created:				31 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-ASP
PORTVERSION=	0.18
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	igor@zynaps.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::ASP.3

.include <bsd.port.mk>
