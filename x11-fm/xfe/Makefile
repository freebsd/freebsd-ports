# New ports collection makefile for:	xfe
# Date created:				Sun, Jul 13 2003
# Whom:					ptiJo
#
# $FreeBSD$
#

PORTNAME=	xfe
PORTVERSION=	0.54.2
PORTREVISION=	0
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ptiJo@noos.fr
COMMENT=	Fast MS-Explorer like filemanager for X

LIB_DEPENDS=	FOX:${PORTSDIR}/x11-toolkits/fox \
		intl.5:${PORTSDIR}/devel/gettext-old \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--with-x
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include/fox|-I${LOCALBASE}/include/|g' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/xfq/Makefile.in \
		${WRKSRC}/xfv/Makefile.in
	@${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings|' ${WRKSRC}/configure

MAN1=		xfe.1 xfq.1 xfv.1

.include <bsd.port.mk>
