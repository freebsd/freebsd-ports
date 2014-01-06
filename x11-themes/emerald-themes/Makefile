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
USES=		gmake shebangfix
USE_AUTOTOOLS=	autoconf:env automake:env aclocal:env autoheader:env
SHEBANG_FILES=	themes/import.sh

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
