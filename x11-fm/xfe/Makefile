# Created by: ptiJo
# $FreeBSD$

PORTNAME=	xfe
PORTVERSION=	1.41
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast MS-Explorer like file manager for X

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16

USES=		desktop-file-utils gmake localbase pathfix
USE_XORG=	xft
USE_GNOME=	intltool
GNU_CONFIGURE=	yes

LDFLAGS+=	-pthread

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=	gettext-tools

post-patch:
.for i in XFileExplorer.cpp help.h xfedefs.h
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/xfe|${DATADIR}|g' ${WRKSRC}/src/${i}
.endfor
	@${REINPLACE_CMD} -e \
		'/<utmp.h>/d' ${WRKSRC}/xvt/ttyinit.c

.include <bsd.port.mk>
