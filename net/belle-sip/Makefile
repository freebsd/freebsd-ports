# $FreeBSD$

PORTNAME=	belle-sip
PORTVERSION=	1.3.0
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/linphone/${PORTNAME}/:source1 \
		http://www.antlr3.org/download/:source2
DISTFILES=	belle-sip-1.3.0.tar.gz:source1 \
		antlr-3.4-complete.jar:source2
EXTRACT_ONLY=	belle-sip-1.3.0.tar.gz

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Belle-sip is a SIP (RFC3261) implementation written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libantlr3c.so:${PORTSDIR}/devel/libantlr3c

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-tests
INSTALL_TARGET=	install-strip
USES=		compiler:c11 gmake libtool pathfix
USE_JAVA=	yes
JAVA_BUILD=	jre
JAVA_VERSION=	1.6+
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	POLARSSL
OPTIONS_DEFAULT=POLARSSL

POLARSSL_CONFIGURE_ENABLE=	tls
POLARSSL_LIB_DEPENDS=		libpolarssl.so:${PORTSDIR}/security/polarssl

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-extract:
	@${CP} ${DISTDIR}/antlr-3.4-complete.jar ${WRKDIR}/antlr-complete.jar

post-patch:
	@${REINPLACE_CMD} -e 's|%%WRKDIR%%|${WRKDIR}|' -e 's|-lrt||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-timezone||' \
		${WRKSRC}/src/belle_sip_headers_impl.c

.include <bsd.port.mk>
