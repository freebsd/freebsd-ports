# Created by: Bob Bomar <bob@bomar.us>
# $FreeBSD$

PORTNAME=		photo_gallery
PORTVERSION=		1.5
PORTREVISION=	6
CATEGORIES=		www
MASTER_SITES=		http://www.capybara.org/~dfraser/photo_gallery/
DISTNAME=		${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.tar

MAINTAINER=		bob@bomar.us
COMMENT=		Simple web based photo gallery

RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm\
		p5-Image-Info>=0:${PORTSDIR}/graphics/p5-Image-Info\
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USE_APACHE_RUN=	22+
USES=		perl5
NO_BUILD=	yes

do-install:
		${MKDIR} ${STAGEDIR}${WWWDIR}/
		@cd ${WRKSRC}; ${FIND} . \
			| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
