# New ports collection makefile for:	bcusdk-eibd
# Date Created:				6 December 2007
# Whom:					Björn König <bkoenig@alpha-tierchen.de>
#
# $FreeBSD$
#

PORTNAME=	bcusdk
PORTVERSION=	0.0.4
CATEGORIES=	net
MASTER_SITES=	http://www.auto.tuwien.ac.at/~mkoegler/eib/
PKGNAMESUFFIX=	-eibd
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	The EIBnet/IP server of the BCU SDK

LIB_DEPENDS=	pthsem.20:${PORTSDIR}/devel/pthsem
BUILD_DEPENDS=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-onlyeibd \
		--disable-usb \
		--enable-eibnetip \
		--enable-eibnetipserver \
		--enable-eibnetiptunnel \
		--enable-groupcache \
		CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib ${CFLAGS}"

OPTIONS=	JAVA "Install Java client library" off \
		EXAMPLES "Install example client applications" on

.include <bsd.port.pre.mk>

.if defined(WITH_JAVA)
CONFIGURE_ARGS+=--enable-java
USE_JAVA=	yes
PLIST_SUB+=	JAVA=""
.else
PLIST_SUB+=	JAVA="@comment "
.endif

.if defined(WITH_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} "s,-ri,-Ei.bak," ${WRKSRC}/eibd/client/php/Makefile.in
	@${REINPLACE_CMD} "s, bcu,," ${WRKSRC}/eibd/Makefile.in
	@${REINPLACE_CMD} "s, php,," ${WRKSRC}/eibd/client/Makefile.in
.if !defined(WITH_EXAMPLES)
	@${REINPLACE_CMD} "s, examples,," ${WRKSRC}/eibd/Makefile.in
.else
	@${REINPLACE_CMD} -e "s,^\(examplesdir = \).*,\1${EXAMPLESDIR}," \
		-e "s,^\(bindir = \).*,\1${EXAMPLESDIR}/bin," \
		${WRKSRC}/eibd/examples/Makefile.in
.endif
.if defined(WITH_JAVA)
	@${REINPLACE_CMD} "s,^\(javadir = \).*,\1${JAVASHAREDIR}," ${WRKSRC}/eibd/client/java/Makefile.in
.endif

.include <bsd.port.post.mk>
