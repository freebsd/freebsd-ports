# New ports collection makefile for:	p5-IO-Socket-SSL
# Date created:				October 27th 2000
# Whom:	      				Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-SSL
PORTVERSION=	0.75
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	scrappy@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay

RESTRICTED=	"Crypto; export-controlled"

USE_PERL5=	yes

$MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
$MAN3=		IO::Socket::SSL.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
