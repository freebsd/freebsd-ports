# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	runwhen
PORTVERSION=	2015.02.24
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://code.dogmap.org/runwhen/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for running commands at particular times

LICENSE=	GPLv2

LIB_DEPENDS=	libskarnet.so:devel/skalibs

USES=		tar:bzip2

WRKSRC=		${WRKDIR}/admin/${DISTNAME}

PLIST_FILES=	bin/rw-add bin/rw-match bin/rw-max bin/rw-min	\
		bin/rw-sleep bin/rw-sub bin/rw-touch

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's!gcc -O2!${CC} ${CFLAGS}!' \
		${WRKSRC}/conf-compile/defaults/host_compile.sh
	@${REINPLACE_CMD} 's!gcc!${CC} ${LDFLAGS} ${LIBS}!' \
		${WRKSRC}/conf-compile/defaults/host_link.sh
	@${REINPLACE_CMD} 's!-lskarnet!-L${LOCALBASE}/lib -lskarnet!' \
		${WRKSRC}/package/compile

do-configure:
	${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-compile/defaults/package_home
	${ECHO_CMD} ${LOCALBASE} > ${WRKSRC}/conf-compile/defaults/depend_skalibs
	${ECHO_CMD} ${LOCALBASE}/lib/skalibs/sysdeps > ${WRKSRC}/conf-compile/defaults/depend_skalibs_sysdeps

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
