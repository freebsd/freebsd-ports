# New ports collection makefile for:	math/p5-Statistics-R
# Date created:				March 7, 2011
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Statistics-R
PORTVERSION=	0.22
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FANGLY
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Controls the R interpreter through Perl

BUILD_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
RUN_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common

PERL_CONFIGURE=	yes

MAN3=		Statistics::R::Legacy.3 \
		Statistics::R::Win32.3 \
		Statistics::R.3

.include <bsd.port.mk>
