# New ports collection makefile for:	p5-Net-RawIP
# Version required:			0.06
# Date created:				18 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

DISTNAME=	Net-RawIP-0.06b
PKGNAME=	p5-Net-RawIP-0.06b
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://quake.skif.net/RawIP/files/ \
		http://www.ic.al.lg.ua/~ksv/
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	dima@chg.ru

USE_PERL5=	yes
MAN3=		Net::RawIP.3 Net::RawIP::libpcap.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:

		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
