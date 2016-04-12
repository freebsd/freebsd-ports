# Created by: Tuc <freebsd-ports@t-b-o-h.net>
# $FreeBSD$

PORTNAME=	MIME-Lite-TT-HTML
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@t-b-o-h.net
COMMENT=	Create html mail with MIME::Lite and TT

BUILD_DEPENDS=	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-HTML-FormatText-WithLinks>=0:textproc/p5-HTML-FormatText-WithLinks
RUN_DEPENDS=	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-HTML-FormatText-WithLinks>=0:textproc/p5-HTML-FormatText-WithLinks

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
