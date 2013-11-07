# Created by: chinsan
# $FreeBSD$

PORTNAME=	HTML-Copy
PORTVERSION=	1.30
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Copy a HTML file without breaking links

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
