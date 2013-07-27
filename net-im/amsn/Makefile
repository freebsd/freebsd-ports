# Created by: Andreas Klemm <andreas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amsn
PORTVERSION=	0.98.9
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Alvano\'s MSN Messenger

DEPRECATED=	Primary MSN Messenger service terminated 30 APR 2013
EXPIRATION_DATE=2013-10-31

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		gstfarsight-0.10.0:${PORTSDIR}/net-im/farsight2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${LOCALBASE}/lib/tls/tls.tcl:${PORTSDIR}/devel/tcltls \
		snack>=2.2.10_4:${PORTSDIR}/audio/snack
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${LOCALBASE}/lib/tls/tls.tcl:${PORTSDIR}/devel/tcltls \
		snack>=2.2.10_4:${PORTSDIR}/audio/snack

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11
USES=		gettext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_TCL=	86
USE_TK=		86

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}

CXXFLAGS+=	-I${LOCALBASE}/include/libpng15
CONFIGURE_ENV+=	CFLAGS+="-I${LOCALBASE}/include" \
		LDFLAGS+="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name '*.c' -or -name '*.h' | ${XARGS} ${REINPLACE_CMD} -e 's|||'
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	${REINPLACE_CMD} -e 's|Linux|FreeBSD|g' ${WRKSRC}/amsn.desktop

post-install:
	@${CHMOD} +x ${DATADIR}/amsn

.include <bsd.port.mk>
