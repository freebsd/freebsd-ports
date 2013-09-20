# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdvbpsi
PORTVERSION=	0.2.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/libdvbpsi/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A library for MPEG TS and DVB PSI tables decoding and generation

LICENSE=	LGPL21

USE_BZIP2=	yes
USES=	pathfix
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
.if defined(WITH_DEBUG)
CONFIGURE_ARGS=		--enable-debug
.else
CONFIGURE_ARGS=		--enable-release
.endif
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-Wall|$${CFLAGS}|g ; \
		 s|-O6||g' ${WRKSRC}/configure

regression-test:
	@(cd ${WRKSRC}/misc && ./test_dr)

.include <bsd.port.mk>
