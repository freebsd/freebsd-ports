# New ports collection makefile for:	Apache-AutoIndex
# Date created:				Sun Dec 31 20:13:11 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AutoIndex
PORTVERSION=	0.08
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/Icon.pm:${PORTSDIR}/www/p5-Apache-Icon \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/Language.pm:${PORTSDIR}/www/p5-Apache-Language \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::AutoIndex.3

.include <bsd.port.mk>
