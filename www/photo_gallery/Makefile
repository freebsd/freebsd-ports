# Created by: Bob Bomar <bob@bomar.us>
# $FreeBSD$

PORTNAME=	photo_gallery
PORTVERSION=	1.5
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://www.capybara.org/~dfraser/photo_gallery/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bob@bomar.us
COMMENT=	Simple web based photo gallery

RUN_DEPENDS=	anytopnm:graphics/netpbm\
		p5-Image-Info>=0:graphics/p5-Image-Info\
		p5-URI>=0:net/p5-URI

USES=		apache:run,2.2+ perl5 shebangfix tar
SHEBANG_FILES=	index.cgi
perl_OLD_CMD=	/usr/pkg/bin/perl
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
