# Created by: Kian Mohageri <kian.mohageri@gmail.com>
# $FreeBSD$

PORTNAME=	nagios-pf-plugin
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
DISTNAME=	check_pf-${PORTVERSION}

MAINTAINER=	rand@iteris.com
COMMENT=	Nagios plugin for checking PF

USE_GITHUB=	yes
GH_ACCOUNT=	kian
GH_PROJECT=	nagios-pf-plugin
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	2aba423

PLIST_FILES=	libexec/nagios/check_pf
PLIST_DIRS=	libexec/nagios/
SUB_FILES=	pkg-message

pre-su-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
