# Created by: Michael Durian <durian@shadetreesoftware.com>
# $FreeBSD$

PORTNAME=	mod_cplusplus
PORTVERSION=	1.5.4
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/modcplusplus/modcplusplus/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for loading C++ objects as handlers

DEPRECATED=	written for apache 2.0, no longer maintained upstream
EXPIRATION_DATE=	2015-02-28

USES=		libtool
USE_APACHE=	22
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs=${APXS}
CPPFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	pkg-message
SUB_LIST=	"APACHEMODDIR=${APACHEMODDIR}"

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} > 1001000
BROKEN=	does not build with new clang
.endif

post-patch:
	${REINPLACE_CMD} -e 's,-Werror,,' ${WRKSRC}/configure.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}

	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_LIB} ${WRKSRC}/src/.libs/libmod_cplusplus.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_cplusplus.so

.include <bsd.port.post.mk>
