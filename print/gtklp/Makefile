# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gtklp
PORTVERSION=	1.3.1
DISTVERSIONSUFFIX=	.src
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK interface to cups

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gettext pkgconfig
USE_GNOME=	gtk20
USE_OPENSSL=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing --copy
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="GtkLP" "" "${PORTNAME}" "${PORTNAME}" "System;GTK;" ""

post-install:
.for i in 16 24 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/libgtklp/icons && ${INSTALL_DATA} ${i}x${i}.xpm \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gtklp.xpm)
.endfor

.include <bsd.port.mk>
