# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	WWW-Google-Video
PORTVERSION=	0.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	An interface to fetch the Google Video Information

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Google::Video.3

NO_STAGE=	yes
.include <bsd.port.mk>
