# New ports collection makefile for:	amsn
# Date created:		01 Feb 2003
# Whom:			Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amsn
PORTVERSION=	0.97.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Alvano\'s MSN Messenger

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib
BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/lib/tls/tls.tcl:${PORTSDIR}/devel/tcltls \
		dtplite:${PORTSDIR}/devel/tcllib
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4

CONFIGURE_ENV=	TK_INC_SPEC=${LOCALBASE}/include/tk8.4/generic

post-patch:
	@${FIND} ${WRKSRC} -name '*.c' -or -name '*.h' | ${XARGS} ${REINPLACE_CMD} -e 's|||'
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	@${CHMOD} +x ${DATADIR}/amsn

.include <bsd.port.mk>
