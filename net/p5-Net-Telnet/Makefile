# New ports collection makefile for:	p5-Net-Telnet
# Version required:		3.01
# Date created:			March 3 1998
# Whom:	      			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $FreeBSD$
#

DISTNAME=       Net-Telnet-3.01
PKGNAME=        p5-Net-Telnet-3.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	kuriyama@opt.phys.waseda.ac.jp

USE_PERL5=	YES

MAN3=		Net::Telnet.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
.include <bsd.port.mk>
