# New ports collection makefile for:		swatch
# Date created:					May 2 97
# Whom:						jfitz
#
# $FreeBSD$
#

PORTNAME=	swatch
PORTVERSION=	3.0.8
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	swatch

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	The Simple WATCHer and filter

BUILD_DEPENDS=	${BUILD_DEPENDS_56} \
	${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
	${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail \
	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLMAN1DIR=${PREFIX}/man/man1

MAN1=	swatch.1 swatch_oldrc2newrc.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS_56=	\
	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.post.mk>
