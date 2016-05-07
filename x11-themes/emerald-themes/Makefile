# $FreeBSD$

PORTNAME=	emerald-themes
PORTVERSION=	0.6.0
CATEGORIES=	x11-themes
MASTER_SITES=	http://cgit.compiz.org/fusion/decorators/emerald-themes/snapshot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for the Emerald Window Decorator

BUILD_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake shebangfix tar:bzip2
SHEBANG_FILES=	themes/import.sh
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
