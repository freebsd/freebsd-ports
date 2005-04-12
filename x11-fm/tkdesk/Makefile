# New ports collection makefile for:	tkdesk
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkdesk
PORTVERSION=	2.0
CATEGORIES=	x11-fm tk83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical, highly configurable and powerful file manager

LIB_DEPENDS=	itcl32:${PORTSDIR}/lang/itcl \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAG="-I${LOCALBASE}/include/itcl3.2" \
		LDFLAGS="-L${LOCALBASE}/lib -litcl32"
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.3 \
		--with-tk=${LOCALBASE}/lib/tk8.3 \
		--with-itcl=${LOCALBASE}/lib/itcl3.2

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

post-patch:
	@${GREP} -lR "<malloc\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

pre-install:
	@${FIND} ${WRKSRC}/tcldesk/configs -type f -name "*.orig" -delete

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/tkdesksh
	@${STRIP_CMD} ${PREFIX}/bin/tkdeskclient
	@${MKDIR} -m 755 ${PREFIX}/lib/TkDesk/configs/.trash

.include <bsd.port.mk>
