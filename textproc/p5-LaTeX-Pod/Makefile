# New ports collection makefile for:	LaTeX-Pod
# Date created:				10 July, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	LaTeX-Pod
PORTVERSION=	0.19
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Transform LaTeX source files to POD

BUILD_DEPENDS=	p5-LaTeX-TOM>=0.9:${PORTSDIR}/textproc/p5-LaTeX-TOM \
		p5-Params-Validate>=0.91:${PORTSDIR}/devel/p5-Params-Validate \
		p5-boolean>=0.20:${PORTSDIR}/devel/p5-boolean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	latex2pod.1
MAN3=	LaTeX::Pod.3

.include <bsd.port.mk>
