# New ports collection makefile for:	fakeroot
# Date created:				11 March 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	fakeroot
PORTVERSION=	1.12.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/f/fakeroot
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Simulate the root user behaviour

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--with-ipc=tcp
USE_AUTOTOOLS=		libtool:22
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MANLANG=	"" es sv fr nl
MAN1=		faked.1 fakeroot.1

pre-configure:
	 @${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
	 	${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${MV} ${PREFIX}/lib/libfakeroot-0.so ${PREFIX}/lib/libfakeroot.so.0
	@${LN} -sf ${PREFIX}/lib/libfakeroot.so.0 ${PREFIX}/lib/libfakeroot-0.so

.include <bsd.port.mk>
