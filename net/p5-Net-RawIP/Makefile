# New ports collection makefile for:	p5-Net-RawIP
# Date created:				18 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-RawIP
PORTVERSION=	0.09d
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://quake.skif.net/RawIP/files/ \
		http://www.ic.al.lg.ua/~ksv/
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org

PERL_CONFIGURE=	yes
MAN3=		Net::RawIP.3 Net::RawIP::libpcap.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
