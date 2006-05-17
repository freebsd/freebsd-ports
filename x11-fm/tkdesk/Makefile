# New ports collection makefile for:	tkdesk
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkdesk
PORTVERSION=	2.0.2
CATEGORIES=	x11-fm tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
PATCHFILES=	${DISTNAME}p1.patch ${DISTNAME}p2.patch
PATCH_SITES=	http://tkdesk.sourceforge.net/patches/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical, highly configurable and powerful file manager

LIB_DEPENDS=	BLT24:${PORTSDIR}/x11-toolkits/blt \
		itcl:${PORTSDIR}/lang/itcl \
		tk84:${PORTSDIR}/x11-toolkits/tk84

PATCH_DIST_STRIP=-p1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ENV+=	LIB_RUNTIME_DIR=${LOCABASE}/lib
CONFIGURE_ENV=	CPPFLAG="-I${LOCALBASE}/include/itcl3.3" \
		LDFLAGS="-L${LOCALBASE}/lib -litcl"
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4 \
		  --with-blt=${LOCALBASE} \
		--with-itcl=${LOCALBASE}/lib/itcl3.3
EXTRACT_AFTER_ARGS=| ${TAR} -xf - --exclude blt

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

post-patch:
	@${GREP} -lR "<malloc\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -delete

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/tkdesksh
	@${STRIP_CMD} ${PREFIX}/bin/tkdeskclient
	@${MKDIR} -m 755 ${PREFIX}/lib/TkDesk/configs/.trash

.include <bsd.port.mk>
