# New ports collection makefile for:   p5-Socks
# Date created:        22 January 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	p5-Socks
PORTVERSION=	0.03
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
DISTNAME=	SOCKS-0.03

MAINTAINER=	nakai@FreeBSD.org

USE_PERL5=	YES

MAN3=		Net::SOCKS.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
