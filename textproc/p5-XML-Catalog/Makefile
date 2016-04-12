# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Catalog
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Resolve public identifiers and remap system identifiers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-Text-ParseWords>0:textproc/p5-Text-ParseWords \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		dos2unix perl5
USE_PERL5=	configure
DOS2UNIX_GLOB=	Catalog.pm

.include <bsd.port.mk>
