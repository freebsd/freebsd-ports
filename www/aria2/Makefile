# New ports collection makefile for:	aria2
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2
DISTVERSION=	0.12.1
CATEGORIES=	www
MASTER_SITES=	SFE

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Yet another download tool

#CPPFLAGS=	-g
#DONTSTRIP=	yes
#CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
#MAKE_ENV=	DONTSTRIP=
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --with-openssl \
		--with-libxml2 --without-gnutls --without-libares \
		--without-libcares --program-transform-name=""

USE_GCC=	3.4+
USE_BZIP2=	yes
USE_GNOME=	gnomehack libxml2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
.ifdef WITHOUT_NLS
CONFIGURE_ARGS+=	--disable-nls
.else
LINGUAS=	ca de es fi fr he it ja nl pt_BR ru sv
.endif
PLIST_FILES=	bin/aria2c \
		${LINGUAS:S|^|share/locale/|:S|$|/LC_MESSAGES/aria2c.mo|}
MAN1=		aria2c.1

post-configure:
	@${REINPLACE_CMD} -e '/SETMODE/d' ${WRKSRC}/config.h

.include <bsd.port.mk>
