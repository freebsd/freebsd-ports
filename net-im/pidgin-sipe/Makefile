# Created by: John Prather
# $FreeBSD$

PORTNAME=	pidgin-sipe
PORTVERSION=	1.13.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF/sipe/sipe/${DISTNAME}

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	A plugin for Pidgin to provide LCS/OCS connectivity

LIB_DEPENDS=	nss3:${PORTSDIR}/security/nss \
		purple.10:${PORTSDIR}/net-im/libpurple
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20
USE_LDCONFIG=	${PREFIX}/lib/pidgin
PORTDOCS=	AUTHORS ChangeLog COPYING HACKING INSTALL NEWS README TODO VERSION

CFLAGS+=	-I/${LOCALBASE}/include
LIBS+=		-L/${LOCALBASE}/lib -lgssapi_krb5

OPTIONS_DEFINE=		OCS2005 KRB5 DOCS NLS
OSC2005_DESC=		Message timeout for OCS2005
KRB5_DESC=		With Kerberos5

CONFIGURE_ARGS+=	--enable-purple \
			--disable-telepathy

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOSC2005}
CONFIGURE_ARGS+=	--enable-ocs2005-message-hack
.endif

.if ${PORT_OPTIONS:MKRB5}
CONFIGURE_ARGS+=	--without-krb5
.endif

CONFIGURE_ENV+=	LIBS="${LIBS}" \
		COM_ERR_CFLAGS="-I/usr/include" \
		COM_ERR_LIBS="-L/usr/lib -lcom_err"

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}/
.endfor
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.include <bsd.port.mk>
