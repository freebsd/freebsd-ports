# New ports collection makefile for:	icqnd
# Date Created:				29 Ago 2006
# Whom:					Rodrigo Graeff <delphus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	icqnd
PORTVERSION=	0.1.9.6
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	delphus@gmail.com
COMMENT=	GTK based LICQ GUI program

BUILD_DEPENDS=	licq:${PORTSDIR}/net-im/licq
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

OPTIONS=	NLS "With native language support" off \
		GTKSPELL "spell checking support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--enable-gtkspell
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
