# New ports collection makefile for:	gtk-imonc
# Date Created:				26. October 2002
# Whom:					Steffen Vogelreuter
#
# $FreeBSD$
#

PORTNAME=	gtk-imonc
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://userpage.fu-berlin.de/~zeank/gtk-imonc/download/

MAINTAINER=	steffen@vogelreuter.de
COMMENT=	A gtk based client to control an one disc fli4l router

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's|ac_default_prefix=/usr/local|ac_default_prefix=${PREFIX}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
