# New ports collection makefile for:	kiltdown
# Date Created:				16 Jun 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	kiltdown
PORTVERSION=	0.8.045
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kiltdown

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kiltdown is an UI independant Email Client for UNIX

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

PLIST_FILES=	bin/kiltdown
USE_X_PREFIX=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
MY_CONFIGURE_ARGS=	-release
MY_CONFIGURE_ARGS+=	-qtinc ${X11BASE}/include -qtlib ${X11BASE}/lib
MY_CONFIGURE_ARGS+=	-dbinc ${LOCALBASE}/include/db3 -dblib ${LOCALBASE}/lib
BUILD_ENV+=		PATH=${PATH}:${X11BASE}/bin

post-patch:
	@${MV} ${WRKSRC}/configs/bsd-generic ${WRKSRC}/configs/bsd-generic.sed
	${SED} \
	 -e "s|SYS_CFLAGS=-pthread|SYS_CFLAGS=${PTHREAD_CFLAGS} ${CFLAGS}|" \
	 -e "s|SYS_LDFLAGS=-pthread|SYS_LDFLAGS=${PTHREAD_LIBS} ${LDFLAGS}|" \
		${WRKSRC}/configs/bsd-generic.sed \
		> ${WRKSRC}/configs/bsd-generic

do-configure:
	(cd ${CONFIGURE_WRKSRC} && \
		./${CONFIGURE_SCRIPT} ${MY_CONFIGURE_ARGS} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kiltdown/kiltdown ${PREFIX}/bin/

.include <bsd.port.mk>
