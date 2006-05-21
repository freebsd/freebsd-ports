# New ports collection makefile for:	aria2
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2
PORTVERSION=	0.4.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Yet another download tool

LIB_DEPENDS=	gnutls.15:${PORTSDIR}/security/gnutls \
		gcrypt.13:${PORTSDIR}/security/libgcrypt

CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

USE_GCC=	3.4+
USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/aria2c share/locale/ja/LC_MESSAGES/aria2c.mo

.include <bsd.port.mk>
