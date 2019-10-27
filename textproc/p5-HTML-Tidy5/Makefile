# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-Tidy5
PORTVERSION=	1.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML validation in a Perl object

LICENSE=	ART20

LIB_DEPENDS=	libtidy5.so:www/tidy-html5

USE_PERL5=	configure
USES=		localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/HTML/Tidy5/Tidy5.so

.include <bsd.port.mk>
