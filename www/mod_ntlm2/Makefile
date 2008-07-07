# New ports collection makefile for:	mod_ntlm2
# Date created:	   26 September 2007
# Whom:		   Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	mod_ntlm2
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modntlm
EXTRACT_SUFX=	.tgz

MAINTAINER=	admin@lissyara.su
COMMENT=	NTLM authentication module for the Apache2 webserver

USE_APACHE=	20+
MAKE_ENV=	APXS=${APXS}

BUILD_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/net/samba3

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
