# New ports collection makefile for:		swatch
# Date created:					May 2 97
# Whom:						jfitz
#
# $FreeBSD$
#

PORTNAME=	swatch
PORTVERSION=	3.0.8
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	swatch

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	The Simple WATCHer and filter

BUILD_DEPENDS=	${site_perl}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
	${site_perl}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail \
	${site_perl}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
	${site_perl}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

site_perl=	${SITE_PERL}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLMAN1DIR=${PREFIX}/man/man1

MAN1=	swatch.1 swatch_oldrc2newrc.1

.include <bsd.port.mk>
