# New ports collection makefile for:    p5-Parallel-UA
# http://www.cs.washington.edu/homes/marclang/ParallelUA/
# Version required:                     2.36
# Date created:                         Sep 8 1998
# Whom:                                 ache@freebsd.org
#
# $Id: Makefile,v 1.2 1998/09/15 21:31:57 asami Exp $
#

DISTNAME=       ParallelUserAgent-2.36
PKGNAME=        p5-ParallelUA-2.36
CATEGORIES=     www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     LWP

MAINTAINER=     ache@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	YES

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=           LWP::Parallel.3 \
		LWP::Parallel::Protocol.3 \
		LWP::Parallel::RobotUA.3 \
		Bundle::ParallelUA.3 \
		LWP::Parallel::UserAgent.3 \
		LWP::ParallelUA.3 \
		LWP::RobotPUA.3

post-patch:
		@ cd ${WRKSRC}/lib/LWP/Parallel; ${RM} *.orig

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
