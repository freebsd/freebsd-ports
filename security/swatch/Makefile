# New ports collection makefile for:		swatch
# Date created:					May 2 97
# Whom:						jfitz
#
# $FreeBSD$
#

PORTNAME=	swatch
PORTVERSION=	3.0.1
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://ftp.stanford.edu/general/security-tools/swatch/

MAINTAINER=	joseph@randomnetworks.com

BUILD_DEPENDS=	${site_perl}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
	${site_perl}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
	${site_perl}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

site_perl=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

USE_PERL5=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	INSTALLMAN1DIR=${PREFIX}/man/man1

MAN1=	swatch.1 swatch_oldrc2newrc.1

.include <bsd.port.mk>
