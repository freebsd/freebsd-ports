# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	umph
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	YouTube video playlist parser for cclive and alike tools

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Getopt-ArgvFile>=1.11:devel/p5-Getopt-ArgvFile \
		p5-Umph-Prompt>=0:multimedia/p5-Umph-Prompt \
		p5-XML-DOM>=1.44:textproc/p5-XML-DOM
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

PLIST_FILES=	bin/umph \
		%%PERL5_MAN1%%/umph.1.gz

.include <bsd.port.mk>
