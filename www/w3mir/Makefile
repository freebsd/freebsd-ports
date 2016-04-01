# Created by: ache
# $FreeBSD$

PORTNAME=	w3mir
PORTVERSION=	1.0.10
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	http://www.langfeldt.net/w3mir/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	All-purpose HTTP copying and mirroring tool

LICENSE=	ART10

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

INSTALL_TARGET=	pure_install

post-install:
	${INSTALL} -d -m 755 \
		${STAGEDIR}${PREFIX}/share/doc/w3mir
	cd ${WRKSRC} && ${INSTALL_DATA} \
		README Artistic w3mir-HOWTO.html example.cfg \
		multiscope.cfg ${STAGEDIR}${PREFIX}/share/doc/w3mir

.include <bsd.port.mk>
