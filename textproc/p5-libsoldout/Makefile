# Created by: Rodrigo OSORIO <rodrigo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsoldout
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROS
PKGNAMEPREFIX=	p5-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Convert Markdown text in (X)HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libsoldout.so:textproc/libsoldout

USES=		perl5
USE_PERL5=	configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/libsoldout/libsoldout.so

.include <bsd.port.mk>
