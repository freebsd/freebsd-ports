# New ports collection makefile for: pidgin-sipe
# Date created:  7 May 2009
# Whom:          John Prather
#
# $FreeBSD$
#

PORTNAME=	pidgin-sipe
PORTVERSION=	1.10.1
CATEGORIES=	net-im
MASTER_SITES=	SF/sipe/sipe/${DISTNAME}

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	A plugin for Pidgin to provide LCS/OCS connectivity

LIB_DEPENDS=	purple.7:${PORTSDIR}/net-im/libpurple
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	${PREFIX}/lib/pidgin
PORTDOCS=	AUTHORS ChangeLog COPYING HACKING INSTALL NEWS README TODO VERSION

CFLAGS+=	"-I/${LOCALBASE}/include"
LIBS+=		"-L/${LOCALBASE}/lib"

CONFIGURE_ARGS+=	--enable-purple \
			--disable-telepathy \
			--without-krb5

CONFIGURE_ENV+=	LIBS="${LIBS}" \
		COM_ERR_CFLAGS="-I/usr/include" \
		COM_ERR_LIBS="-L/usr/lib -lcom_err"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}/
.endfor
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.include <bsd.port.mk>
