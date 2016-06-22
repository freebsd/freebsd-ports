# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbsigntool
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+files/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Signing utility for UEFI secure boot

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libgnuefi.a:devel/gnu-efi \
		help2man:misc/help2man
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	libcrypto_CFLAGS=-lcrypto libcrypto_LIBS=-lcrypto LOCALBASE=${LOCALBASE} ac_cv_header_bfd_h=yes
USES=		gmake pkgconfig

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		This port works only on FreeBSD 10 and newer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<endian.h>|<sys/endian.h>|' ${WRKSRC}/configure ${WRKSRC}/lib/ccan/ccan/hash/hash.c

.include <bsd.port.post.mk>
