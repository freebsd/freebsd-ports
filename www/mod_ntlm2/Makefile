# Created by: Alex "lissyara" Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	mod_ntlm2
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/modntlm/modntlm2/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	admin@lissyara.su
COMMENT=	NTLM authentication module for the Apache2 webserver

BUILD_DEPENDS=	smbclient:${PORTSDIR}/${SAMBA_PORT}

SAMBA_PORT?=	net/samba36

MAKE_JOBS_SAFE=	yes

USE_APACHE=	22
MAKE_ENV=	APXS=${APXS}

.include <bsd.port.mk>
