# $FreeBSD$

PORTNAME=	otr
PORTVERSION=	4.0.0
# Please do not bump PORTREVISION for this port unless you have
# confirmed via testing that it is necessary
PORTREVISION=	1
CATEGORIES=	security net-im net
MASTER_SITES=	http://www.cypherpunks.ca/otr/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Allows deniable private conversations using Pidgin

BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	libotr.so:${PORTSDIR}/security/libotr \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libpurple.so:${PORTSDIR}/net-im/libpurple

USE_GNOME=	intltool
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-libotr-prefix=${LOCALBASE}/lib \
		--with-libotr-inc-prefix=${LOCALBASE}/include

.include <bsd.port.mk>
