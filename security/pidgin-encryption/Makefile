# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	pidgin
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}-encrypt/Releases/${PORTVERSION}
PKGNAMESUFFIX=	-encryption
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	perlfu@gmail.com
COMMENT=	Encryption Plugin for the Pidgin instant messenger client

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	libpurple.so:${PORTSDIR}/net-im/libpurple \
		libnss3.so:${PORTSDIR}/security/nss

USE_GNOME=	gtk20
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-static \
		--with-nspr-includes=${LOCALBASE}/include/nspr	\
		--with-nspr-libs=${LOCALBASE}/lib	\
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib/nss

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-extract:
	@${REINPLACE_CMD} -e 's|glib/.*\.h"|glib.h"|g' ${WRKSRC}/rsa_nss.c

.include <bsd.port.mk>
