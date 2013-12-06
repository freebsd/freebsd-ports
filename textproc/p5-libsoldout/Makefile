# Created by: Rodrigo OSORIO <rodrigo@bebik.net>
# $FreeBSD$

PORTNAME=	libsoldout
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROS
PKGNAMEPREFIX=	p5-

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Convert Markdown text in (X)HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libsoldout.so:${PORTSDIR}/textproc/libsoldout

USES=		perl5
USE_PERL5=	configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/libsoldout/libsoldout.so

.include <bsd.port.mk>
