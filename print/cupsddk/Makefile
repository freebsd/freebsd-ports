# New ports collection makefile for:	cupsddk
# Date created:		2007-07-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/print/cupsddk/Makefile,v 1.1 2007/12/02 18:35:31 ahze Exp $

PORTNAME=	cupsddk
PORTVERSION=	1.2.3
PORTREVISION=	7
CATEGORIES=	print devel
MASTER_SITES=	EASYSW
MASTER_SITE_SUBDIR=	${PORTNAME}/${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CUPS Driver Development Kit

LIB_DEPENDS=	cupsimage.2:${PORTSDIR}/print/cups-image

WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262
USE_GMAKE=	yes

OPTIONS=	X11	"built with FLTK gui" on

MAN1=	commandtoescpx.1 commandtopclx.1 cupsprofile.1 ppdc.1 ppdhtml.1 \
	ppdi.1 ppdmerge.1 ppdpo.1 rastertoescpx.1 rastertopclx.1
MAN5=	ppdcfile.5

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_X11)
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
CONFIGURE_ARGS+=	--with-fltk
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/cupsprofile.ppm|${DATADIR:S,${PREFIX}/share,,}/cupsprofile.ppm|' \
		${WRKSRC}/cups/cupsprofile.c
	@${REINPLACE_CMD} -e 's|ln -s|${LN} -sf|' \
		${WRKSRC}/Makedefs.in

post-install:
	@${INSTALL_DATA} ${WRKSRC}/cups/cupsprofile.ppm ${DATADIR}

.include <bsd.port.post.mk>
