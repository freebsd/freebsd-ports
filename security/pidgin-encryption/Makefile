# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	pidgin
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}-encrypt/Releases/${PORTVERSION}
PKGNAMESUFFIX=	-encryption
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	perlfu@gmail.com
COMMENT=	Encryption Plugin for the Pidgin instant messenger client

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	purple.10:${PORTSDIR}/net-im/libpurple \
		nss3:${PORTSDIR}/security/nss

USE_GNOME=	gtk20
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-nspr-includes=${LOCALBASE}/include/nspr	\
		--with-nspr-libs=${LOCALBASE}/lib	\
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib/nss

NO_STAGE=	yes

OPTIONS_DEFINE=	NLS 

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h"|glib.h"|g' ${WRKSRC}/rsa_nss.c

.include <bsd.port.mk>
