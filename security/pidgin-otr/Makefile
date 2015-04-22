# $FreeBSD$

PORTNAME=	otr
PORTVERSION=	4.0.0
PORTREVISION=	5
CATEGORIES=	security net-im net
MASTER_SITES=	http://www.cypherpunks.ca/otr/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	chris@bsdjunk.com
COMMENT=	Allows deniable private conversations using Pidgin

LICENSE=	GPLv2

# explicitly use libotr.so.5 (see ports/186944)
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	libotr.so.5:${PORTSDIR}/security/libotr \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libpurple.so:${PORTSDIR}/net-im/libpurple

USES=		cpe gettext gmake libtool pkgconfig
CPE_VENDOR=	cypherpunks
CPE_PRODUCT=	${PKGNAMEPREFIX}${PORTNAME}
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-libotr-prefix=${LOCALBASE}/lib \
		--with-libotr-inc-prefix=${LOCALBASE}/include

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000036 && ${ARCH} == i386
LDFLAGS+=	-lssp_nonshared
.endif

.include <bsd.port.mk>
