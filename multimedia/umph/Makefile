# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	umph
PORTVERSION=	0.2.5
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	YouTube video playlist parser for cclive and alike tools

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-Umph-Prompt>=0:${PORTSDIR}/multimedia/p5-Umph-Prompt \
		p5-XML-DOM>=1.44:${PORTSDIR}/textproc/p5-XML-DOM
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN1=		umph.1
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/auto/umph
PLIST_FILES=	bin/umph \
		${SITE_PERL_REL}/${PERL_ARCH}/auto/umph/.packlist

.include <bsd.port.mk>
