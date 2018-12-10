# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbsigntool
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+files/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Signing utility for UEFI secure boot

LICENSE=	GPLv3

BROKEN=		fails to build

BUILD_DEPENDS=	${LOCALBASE}/lib/libgnuefi.a:devel/gnu-efi \
		help2man:misc/help2man
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	libcrypto_CFLAGS=-lcrypto \
		libcrypto_LIBS=-lcrypto \
		LOCALBASE=${LOCALBASE} \
		ac_cv_header_bfd_h=yes
USES=		gmake localbase pkgconfig ssl
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

post-patch:
	@${REINPLACE_CMD} -e 's|<endian.h>|<sys/endian.h>|' ${WRKSRC}/configure ${WRKSRC}/lib/ccan/ccan/hash/hash.c

.include <bsd.port.mk>
