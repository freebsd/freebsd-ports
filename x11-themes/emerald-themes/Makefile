# $FreeBSD$

PORTNAME=	emerald-themes
PORTVERSION=	0.6.0
CATEGORIES=	x11-themes
MASTER_SITES=	http://cgit.compiz.org/fusion/decorators/emerald-themes/snapshot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for the Emerald Window Decorator

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:env automake:env aclocal:env autoheader:env

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' \
			${WRKSRC}/themes/import.sh

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
