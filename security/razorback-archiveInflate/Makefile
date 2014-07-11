# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	archiveInflate
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/razorbacktm/Nuggets
PKGNAMEPREFIX=	razorback-
DIST_SUBDIR=	razorback

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for an intelligence driven security - Archive Inflator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librazorback_api.so:${PORTSDIR}/security/razorback-api
BUILD_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget
RUN_DEPENDS=	razorback-masterNugget>=0.5.0:${PORTSDIR}/security/razorback-masterNugget

RB_LIBDIR?=	${PREFIX}/lib/razorback
GNU_CONFIGURE=	yes
USES=		libtool pkgconfig
USE_LDCONFIG=	${RB_LIBDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG ASSERT

ASSERT_DESC=	Enable Asserts
ASSERT_CONFIGURE_ENABLE=	assert
DEBUG_CONFIGURE_ENABLE=	debug

post-patch:
	@${REINPLACE_CMD} '/CWARNINGS/ s|-Werror||' ${WRKSRC}/configure

post-install:
	${LN} -sf ${RB_LIBDIR}/archiveInflate.so.2 \
		${STAGEDIR}${RB_LIBDIR}/archiveInflate.so.2.0.0

.include <bsd.port.mk>
