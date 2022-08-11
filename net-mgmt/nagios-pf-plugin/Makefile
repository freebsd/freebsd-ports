PORTNAME=	nagios-pf-plugin
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	rand@iteris.com
COMMENT=	Nagios plugin for checking PF

USE_GITHUB=	yes
GH_ACCOUNT=	kian
GH_TAGNAME=	2aba423

PLIST_FILES=	libexec/nagios/check_pf
SUB_FILES=	pkg-message

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
