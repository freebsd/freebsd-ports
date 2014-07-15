# Created by: Lukasz Wasikowski <lukasz@wasikowski.net>
# $FreeBSD$

PORTNAME=	mod_mpm_itk
PORTVERSION=	2.4.7
CATEGORIES=	www
MASTER_SITES=	http://mpm-itk.sesse.net/ \
		http://lukasz.wasikowski.net/files/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	mpm-itk-2.4.7-02

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	This MPM allows you to run each vhost under a separate uid and gid

LICENSE=	APACHE20

USE_APACHE=	24
GNU_CONFIGURE=	yes

AP_FAST_BUILD=	yes
SRC_FILE=	mpm_itk.c

PLIST_SUB=	SED=${SED}

.include <bsd.port.mk>
