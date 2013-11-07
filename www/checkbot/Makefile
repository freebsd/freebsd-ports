# Created by: wosch@FreeBSD.org
# $FreeBSD$

PORTNAME=	checkbot
PORTVERSION=	1.80
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Checkbot%20${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A WWW link verifier, similar to momspider

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-Time-Duration>=0:${PORTSDIR}/devel/p5-Time-Duration
RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-Time-Duration>=0:${PORTSDIR}/devel/p5-Time-Duration

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/checkbot \
		${SITE_PERL:S!${LOCALBASE}/!!}/${PERL_ARCH}/auto/checkbot/.packlist \
		man/man1/checkbot.1.gz
PLIST_DIRS=	${SITE_PERL:S!${LOCALBASE}/!!}/${PERL_ARCH}/auto/checkbot

.include <bsd.port.mk>
