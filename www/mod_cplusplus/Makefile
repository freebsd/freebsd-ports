# Created by: Michael Durian <durian@shadetreesoftware.com>
# $FreeBSD$

PORTNAME=	mod_cplusplus
PORTVERSION=	1.5.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/modcplusplus/modcplusplus/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for loading C++ objects as handlers


USE_APACHE=	22
USE_AUTOTOOLS=	autoconf autoheader libtool automake aclocal
CFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS+=	-a

SUB_FILES=	pkg-message
SUB_LIST=	"APACHEMODDIR=${APACHEMODDIR}"

WRKSRC=	${WRKDIR}/${PORTNAME}

post-extract:
	${REINPLACE_CMD} -e 's,-Werror,,' ${WRKSRC}/configure.in

pre-configure:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --force --copy)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}

	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libmod_cplusplus.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_cplusplus.so

.include <bsd.port.mk>
