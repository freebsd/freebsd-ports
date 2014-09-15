# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pcmanfm
PORTVERSION=	1.2.2
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/PCManFM/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	PCMan File Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libfm-gtk.so:${PORTSDIR}/x11/libfm

USES=		desktop-file-utils fam gmake pathfix pkgconfig tar:xz libtool
USE_GNOME=	gtk20
USE_AUTOTOOLS=	aclocal automake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS NEWS

OPTIONS_DEFINE=	DEBUG DOCS NLS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e '/pcmanfm.conf/ d' ${WRKSRC}/data/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/default/
	${INSTALL_DATA} ${WRKSRC}/data/pcmanfm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/default/pcmanfm.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
