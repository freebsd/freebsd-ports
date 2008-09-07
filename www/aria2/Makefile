# New ports collection makefile for:	aria2
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2
DISTVERSION=	0.15.3
CATEGORIES=	www
MASTER_SITES=	SFE
DISTNAME=	${PORTNAME}c-${DISTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Yet another download tool

CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --with-openssl \
		--with-libxml2 --without-gnutls --without-libares \
		--without-libcares --program-transform-name=""

USE_BZIP2=	yes
USE_GNOME=	gnomehack libxml2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
.ifdef WITHOUT_NLS
CONFIGURE_ARGS+=	--disable-nls
.else
LINGUAS=	bg ca da de es el fi fr he hu id it ja nl nn pl pt_BR ru sv th tr zh_CN
.endif
PLIST_FILES=	bin/aria2c \
		${LINGUAS:S|^|share/locale/|:S|$|/LC_MESSAGES/aria2c.mo|}
MAN1=		aria2c.1

post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-dist_docDATA||'\
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e '/SETMODE/d' ${WRKSRC}/config.h

.include <bsd.port.mk>
