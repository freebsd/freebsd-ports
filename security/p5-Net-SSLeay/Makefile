# New ports collection makefile for:	p5-Net-SSLeay
# Date created:				April 17th 2000
# Whom:	      				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Net-SSLeay
PORTVERSION=	1.05
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
DISTNAME=	Net_SSLeay.pm-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	andreas@FreeBSD.org

RESTRICTED=	"Cryptography"
USE_PERL5=	yes
USE_OPENSSL=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::SSLeay.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			${OPENSSLBASE} CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
