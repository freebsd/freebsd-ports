# New ports collection makefile for:    scim
# Date created:		20 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim
PORTVERSION=	0.99.4
CATEGORIES=	textproc
MASTER_SITES=	http://freedesktop.org/~suzhe/sources/

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	Smart Common Input Method platform

USE_GNOME=	gtk20 gconf2 lthack

USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 499999
BROKEN=		"4.x lacks C99 compliant wctypes implementation"
.endif

post-configure:
	${REINPLACE_CMD} '/^pkgconfigdir/s|$$(libdir)|$${exec_prefix}/libdata|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} '/^scim_setup_LDFLAGS/s|=|= ${PTHREAD_LIBS}|g' \
		${WRKSRC}/extras/setup/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type make post-install

.include <bsd.port.post.mk>
