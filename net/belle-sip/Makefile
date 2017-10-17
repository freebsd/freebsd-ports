# $FreeBSD$

PORTNAME=	belle-sip
PORTVERSION=	1.5.0
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	SAVANNAH/linphone/${PORTNAME}/ \
		http://www.antlr3.org/download/:source2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		antlr-3.4-complete.jar:source2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belle-sip is a SIP (RFC3261) implementation written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libbctoolbox.so:net/bctoolbox

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-strict --disable-tests \
		--with-antlr=${LOCALBASE}
INSTALL_TARGET=	install-strip
USES=		compiler:c11 gmake libtool pathfix pkgconfig
USE_JAVA=	yes
JAVA_BUILD=	jre
JAVA_VERSION=	1.6+
USE_LDCONFIG=	yes

post-extract:
	@${CP} ${DISTDIR}/antlr-3.4-complete.jar ${WRKDIR}/antlr-complete.jar

post-patch:
	@${REINPLACE_CMD} -e 's|%%WRKDIR%%|${WRKDIR}|' -e 's|-lrt||' \
		${WRKSRC}/configure

.include <bsd.port.mk>
