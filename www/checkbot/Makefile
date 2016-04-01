# Created by: wosch@FreeBSD.org
# $FreeBSD$

PORTNAME=	checkbot
PORTVERSION=	1.80
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Checkbot%20${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	WWW link verifier, similar to momspider

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-Time-Duration>=0:devel/p5-Time-Duration
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-Time-Duration>=0:devel/p5-Time-Duration

USES=		cpe perl5
CPE_VENDOR=	degraaff
USE_PERL5=	configure

PLIST_FILES=	bin/checkbot ${SITE_MAN1}/checkbot.1.gz

.include <bsd.port.mk>
