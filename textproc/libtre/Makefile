# ex:ts=8
# Ports collection makefile for:	libtre
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libtre
PORTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://laurikari.net/tre/
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A lightweight fully POSIX compliant regexp matching library

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig lthack
USE_GETOPT_LONG=	yes
USE_INC_LIBTOOL_VER=	13
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lintl

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.ifdef WITH_OPTIMIZED_CFLAGS
CFLAGS+=	-Wuninitialized -ffast-math -finline-functions -fomit-frame-pointer -fexpensive-optimizations -fforce-mem -fforce-addr -O3
.endif

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS'
	@${ECHO_MSG} "===> For example, 'make WITH_OPTIMIZED_CFLAGS=yes'"
.endif
	@${ECHO_MSG} '===>'

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in tre-api.html tre-syntax.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
