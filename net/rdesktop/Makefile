# New ports collection makefile for:  rdesktop
# Date created:               13 December 2000
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	rdesktop
PORTVERSION=	1.0.0.p19.7.6
PORTREVISION=	1
CATEGORIES=	net comms
MASTER_SITES=	http://bibl4.oru.se/projects/rdesktop/dist/releases/
DISTNAME=	rdesktop-1.0.0

PATCH_SITES=	http://bibl4.oru.se/projects/rdesktop/ \
		http://bibl4.oru.se/projects/rdesktop/patch19/
PATCHFILES=	rdesktop-unified-patch19-7-6.bz2
PATCH_DIST_STRIP=	-p2

MAINTAINER=	chris@aims.com.au

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes

MAN1=		rdesktop.1
ALL_TARGET=

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500023
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
.endif

do-patch:
	@${EXTRACT_CMD} -dc ${_DISTDIR}/${PATCHFILES} | \
		${PATCH} ${PATCH_DIST_ARGS}
.if ${OSVERSION} > 500023
	@${REINPLACE_CMD} -e 's:-O2.*-Wall:${CFLAGS} -I${LOCALBASE}/include:g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:-lgmp:-L${LOCALBASE}/lib -lgmp:g' \
		${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} -e 's:-O2.*-Wall:${CFLAGS}:g' ${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} -e 's:/usr/X11R6/:${X11BASE}/:g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:^PREFIX.*:PREFIX=${PREFIX}:g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:^install.*:install\: rdesktop:g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:^.*(INSTALL) rdp-srvr.*::g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:<endian.h>:<machine/endian.h>:g' \
		${WRKSRC}/rdesktop.h

.include <bsd.port.post.mk>
