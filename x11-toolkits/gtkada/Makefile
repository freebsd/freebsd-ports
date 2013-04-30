# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	gtkada
PORTVERSION=	${GTKADA_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gtkada-rm-${GTKADA_VERSION}${EXTRACT_SUFX}

MAINTAINER=	draco@marino.st
COMMENT=	Ada graphical toolkit based on Gtk2+

LICENSE=	GPLv2

BUILD_DEPENDS+= makeinfo:${PORTSDIR}/print/texinfo
BUILD_DEPENDS+= gtk>=${GTKADA_VERSION}:${PORTSDIR}/x11-toolkits/gtk20
RUN_DEPENDS+=	gtk>=${GTKADA_VERSION}:${PORTSDIR}/x11-toolkits/gtk20

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USES+=		ada

GTKADA_VERSION=		2.22
PLIST_SUB+=		PKGNAME="${PORTNAME}-${GTKADA_VERSION}"

CONFIGURE_ARGS+=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/src/misc.c

.include <bsd.port.mk>
