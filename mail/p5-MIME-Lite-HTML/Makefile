# New ports collection makefile for:	p5-MIME-Lite-HTML
# Date created:				2004-06-23 18:16:13
# Whom:	      				Jean-Baptiste Quenot <jb.quenot@caraldi.com>
#
# $FreeBSD$
#

PORTNAME=	MIME-Lite-HTML
PORTVERSION=	1.24
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chifeng@gmail.com
COMMENT=	Provide routine to transform a HTML page into a MIME mail

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-MIME-Lite>=1:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-MIME-Lite>=1:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		MIME::Lite::HTML.3

.include <bsd.port.mk>
