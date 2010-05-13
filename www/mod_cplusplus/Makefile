# Ports collection makefile for:	mod_cplusplus for Apache 2.x
# Date created:		Dec 29, 2006
# Whom:			Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	mod_cplusplus
PORTVERSION=	1.5.4
CATEGORIES=	www
MASTER_SITES=	SF/modcplusplus/modcplusplus/${PORTNAME}-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for loading C++ objects as handlers

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+
USE_AUTOTOOLS=	autoconf:262 autoheader:262 libtool:22 automake:19 aclocal:19
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
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/${APACHEINCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libmod_cplusplus.so ${PREFIX}/${APACHEMODDIR}/mod_cplusplus.so

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
