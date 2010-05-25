# New ports collection makefile for:	mod_ntlm2
# Date created:	   26 September 2007
# Whom:		   Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	mod_ntlm2
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/modntlm/modntlm2/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	admin@lissyara.su
COMMENT=	NTLM authentication module for the Apache2 webserver

BUILD_DEPENDS=	smbclient:${PORTSDIR}/net/samba3

USE_APACHE=	20+
MAKE_ENV=	APXS=${APXS}

.include <bsd.port.mk>
