# New ports collection makefile for:	tkdesk
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkdesk
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	x11-fm tk
MASTER_SITES=	SF/${PORTNAME}/TkDesk/2.0
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
PATCHFILES=	${DISTNAME}p1.patch ${DISTNAME}p2.patch
PATCH_SITES=	http://tkdesk.sourceforge.net/patches/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical, highly configurable and powerful file manager

LIB_DEPENDS=	BLT24:${PORTSDIR}/x11-toolkits/blt \
		itcl:${PORTSDIR}/lang/itcl

EXTRACT_AFTER_ARGS=| ${TAR} -xf - --exclude blt
PATCH_DIST_STRIP=-p1

USE_TCL_BUILD=	yes
USE_TCL=	yes
USE_TK_BUILD=	yes
USE_TK=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-blt=${LOCALBASE} \
		--with-itcl=${LOCALBASE}/lib/itcl3.4
MAKE_ENV=	LIB_RUNTIME_DIR="${LOCABASE}/lib"

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

CPPFLAG=	-I${LOCALBASE}/include/itcl3.4
LDFLAGS=	-L${LOCALBASE}/lib -litcl

post-patch:
	@${GREP} -lR "<malloc\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e 's|%%TCLSH%%|${TCLSH}|g' ${WRKSRC}/Makefile.in

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -delete

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/tkdesksh
	@${STRIP_CMD} ${PREFIX}/bin/tkdeskclient
	@${MKDIR} -m 755 ${PREFIX}/lib/TkDesk/configs/.trash

.include <bsd.port.mk>
