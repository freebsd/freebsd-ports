# ex:ts=8
# Ports collection makefile for:	libdvbpsi
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdvbpsi
PORTVERSION=	0.1.6
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdvbpsi/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	${PORTNAME}5-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A library for MPEG TS and DVB PSI tables decoding and generation

USE_DOS2UNIX=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
.if defined(WITH_DEBUG)
CONFIGURE_ARGS=		--enable-debug
.else
CONFIGURE_ARGS=		--enable-release
.endif
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall|$${CFLAGS}|g ; \
		 s|-O6||g' ${WRKSRC}/configure

regression-test:
	@(cd ${WRKSRC}/misc && ./test_dr)

.include <bsd.port.mk>
