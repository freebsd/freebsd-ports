# New ports collection makefile for:	IExtract
# Date created:		19 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IExtract
PORTVERSION=	0.8.11
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Extract meta-information from files

LIB_DEPENDS=	YGP-0.8.10.0:${PORTSDIR}/devel/libYGP

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
PLIST_FILES=	bin/IExtract \
		share/locale/de/LC_MESSAGES/IExtract.mo \
		share/locale/en/LC_MESSAGES/IExtract.mo \
		share/locale/es/LC_MESSAGES/IExtract.mo

.include <bsd.port.mk>
