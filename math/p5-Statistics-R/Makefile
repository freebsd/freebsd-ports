# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Statistics-R
PORTVERSION=	0.31
PORTREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FANGLY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Controls the R interpreter through Perl

BUILD_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
RUN_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
