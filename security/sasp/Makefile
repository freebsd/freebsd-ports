# Created by: sviat
# $FreeBSD$

PORTNAME=	sasp
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~ahze/distfiles/
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	sviat@OpenGEEKS.it
COMMENT=	A tool that permits to use a gateway whatever IP we have

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

NO_WRKSUBDIR=	yes
MAKE_ENV=	LIBNET_CONFIG="${LIBNET_CONFIG}"
PLIST_FILES=	sbin/sasp

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

NO_STAGE=	yes
.include <bsd.port.mk>
