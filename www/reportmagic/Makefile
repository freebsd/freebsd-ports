# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	reportmagic
PORTVERSION=	2.21
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.reportmagic.org/	\
		http://www.reportmagic.org.uk/	\
		http://www.reportmagic.de/	\
		http://be.reportmagic.org/
DISTNAME=	rmagic-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web site statistics post-processor for Analog

RUN_DEPENDS=	analog:www/analog \
		p5-GD-Graph3d>=0:graphics/p5-GD-Graph3d \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Config-IniFiles>=0:devel/p5-Config-IniFiles

USES=		perl5 shebangfix
SHEBANG_FILES=	rmagic.pl
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${PERL5} Install.PL -no_modules

.include <bsd.port.mk>
