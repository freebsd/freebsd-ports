# New ports collection makefile for:	xfe
# Date created:				Sun, Jul 13 2003
# Whom:					ptiJo
#
# $FreeBSD$
#

PORTNAME=	xfe
PORTVERSION=	0.80
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast MS-Explorer like filemanager for X

LIB_DEPENDS=	FOX-1.4:${PORTSDIR}/x11-toolkits/fox-devel \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--with-x
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include/fox|-I${LOCALBASE}/include/|g' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/xfq/Makefile.in \
		${WRKSRC}/xfv/Makefile.in
	@${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings| ; \
		s|-lFOX|${PTHREAD_LIBS} &|g' ${WRKSRC}/configure

MAN1=		xfe.1 xfi.1 xfq.1 xfv.1

.include <bsd.port.mk>
