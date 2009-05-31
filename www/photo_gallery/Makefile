# New ports collection makefile for: 	photo_gallery
# Date created:				Feb 5 2003
# Whom:					Bob Bomar <bob@bomar.us>
#
# $FreeBSD$

PORTNAME=		photo_gallery
PORTVERSION=		1.5
PORTREVISION=	1
CATEGORIES=		www
MASTER_SITES=		http://www.capybara.org/~dfraser/photo_gallery/
DISTNAME=		${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.tar

MAINTAINER=		bob@bomar.us
COMMENT=		Simple web based photo gallery

RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm\
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info\
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

USE_APACHE=	1.3
USE_PERL5=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} ${WWWDIR}/
		@cd ${WRKSRC}; ${FIND} . \
			| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

.include <bsd.port.mk>
