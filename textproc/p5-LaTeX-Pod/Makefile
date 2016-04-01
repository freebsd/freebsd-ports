# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	LaTeX-Pod
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Transform LaTeX source files to POD

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-LaTeX-TOM>=0.9:textproc/p5-LaTeX-TOM \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Params-Validate>=0.91:devel/p5-Params-Validate \
		p5-boolean>=0.20:devel/p5-boolean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
