# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Statistics-R
PORTVERSION=	0.34
PORTREVISION=	4
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FANGLY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Controls the R interpreter through Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	R:math/R
RUN_DEPENDS=	R:math/R \
		p5-IPC-Run>=0.10:devel/p5-IPC-Run \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
