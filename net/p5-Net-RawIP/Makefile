# New ports collection makefile for:	p5-Net-RawIP
# Date created:				18 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	p5-Net-RawIP
PORTVERSION=	0.09
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://quake.skif.net/RawIP/files/ \
		http://www.ic.al.lg.ua/~ksv/
MASTER_SITE_SUBDIR=	Net
DISTNAME=	Net-RawIP-${PORTVERSION}

MAINTAINER=	dima@chg.ru

USE_PERL5=	yes
MAN3=		Net::RawIP.3 Net::RawIP::libpcap.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:

		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
