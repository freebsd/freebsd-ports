# New ports collection makefile for:	p5-Net-Telnet
# Date created:			March 3 1998
# Whom:	      			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	Net-Telnet
PORTVERSION=	3.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org

USE_PERL5=	yes

MAN3=		Net::Telnet.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
