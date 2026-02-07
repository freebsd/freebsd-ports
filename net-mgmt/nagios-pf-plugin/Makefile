PORTNAME=	nagios-pf-plugin
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	rand@iteris.com
COMMENT=	Nagios plugin for checking PF
WWW=		https://github.com/kian/nagios-pf-plugin/

# https://reviews.freebsd.org/D41651
BROKEN_FreeBSD_15=	requires no longer supported ioctl(DIOCGETSTATUS)

DEPRECATED=	dead upstream, broken on FreeBSD 15
EXPIRATION_DATE=	2026-03-31

USE_GITHUB=	yes
GH_ACCOUNT=	kian
GH_TAGNAME=	2aba423

PLIST_FILES=	libexec/nagios/check_pf
SUB_FILES=	pkg-message

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
