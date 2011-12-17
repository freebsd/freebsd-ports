# New ports collection makefile for:	claws-mail-gdata
# Date created:		2011-12-17
# Whom:			Pawel Pekala <pawel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdata
PORTVERSION=	0.3
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	${PORTNAME}_plugin-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Plugin providing Google Contacts in the Tab-address completion

LICENSE=	GPLv3

BUILD_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail
LIB_DEPENDS=	gdata:${PORTSDIR}/devel/libgdata
RUN_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
