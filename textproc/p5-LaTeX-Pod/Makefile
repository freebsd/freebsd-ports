# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	LaTeX-Pod
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Transform LaTeX source files to POD

BUILD_DEPENDS=	p5-LaTeX-TOM>=0.9:${PORTSDIR}/textproc/p5-LaTeX-TOM \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Params-Validate>=0.91:${PORTSDIR}/devel/p5-Params-Validate \
		p5-boolean>=0.20:${PORTSDIR}/devel/p5-boolean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	latex2pod.1
MAN3=	LaTeX::Pod.3

.include <bsd.port.mk>
