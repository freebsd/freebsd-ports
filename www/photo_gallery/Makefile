# New ports collection makefile for: 	photo_gallery
# Date created:				Feb 5 2003
# Whom:					Bob Bomar <bob@bomar.us>
#
# $FreeBSD$

PORTNAME=		photo_gallery
PORTVERSION=		1.5
CATEGORIES=		www
MASTER_SITES=		http://www.capybara.org/~dfraser/photo_gallery/
DISTNAME=		${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.tar

MAINTAINER=		bob@bomar.us
COMMENT=		Simple web based photo gallery

RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm\
		${LOCALBASE}/etc/apache/httpd.conf:${PORTSDIR}/www/apache13\
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info\
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

WEBOWN?=	www
WEBGRP?=	www
APACHEDIR=	${LOCALBASE}/www/data
INSTALLDIR=	${APACHEDIR}/photo
NO_BUILD=	yes
USE_PERL5=	yes
USE_GZIP=	no

do-install:
		${MKDIR} ${INSTALLDIR}
		cd ${WRKSRC}; ${FIND} . \
			| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}
.include <bsd.port.mk>
