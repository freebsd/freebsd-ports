# New ports collection makefile for:	scanbuttond
# Date created:		31 March 2006
# Whom:			Daniel Thiele
#
# $FreeBSD$
#

PORTNAME=	scanbuttond
PORTVERSION=	0.2.3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	dthiele@gmx.net
COMMENT=	A daemon to monitor and configure modern scanner's buttons

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES+=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

pre-configure:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|-ldl||g'
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
