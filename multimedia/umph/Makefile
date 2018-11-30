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

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Getopt-ArgvFile>=1.11:devel/p5-Getopt-ArgvFile \
		p5-Umph-Prompt>=0:multimedia/p5-Umph-Prompt \
		p5-XML-DOM>=1.44:textproc/p5-XML-DOM

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PLIST_FILES=	bin/umph \
		${SITE_MAN1_REL}/umph.1.gz

.include <bsd.port.mk>
