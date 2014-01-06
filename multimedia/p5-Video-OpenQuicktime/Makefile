# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	Video-OpenQuicktime
PORTVERSION=	1.02
PORTREVISION=	5
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to the OpenQuicktime library

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline
LIB_DEPENDS=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime
RUN_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
