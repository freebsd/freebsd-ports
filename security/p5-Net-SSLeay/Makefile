# New ports collection makefile for:	p5-Net-SSLeay
# Date created:				April 17th 2000
# Whom:	      				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	p5-Net-SSLeay
PORTVERSION=	1.05
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
DISTNAME=	 Net_SSLeay.pm-1.05

MAINTAINER=	andreas@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
FORBIDDEN=	infinite loop trying to find OpenSSL
.endif

RESTRICTED=	"Cryptography"
USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::SSLeay.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.post.mk>
