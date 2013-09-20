# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	gbdfed
PORTVERSION=	1.6
CATEGORIES=	x11-fonts
MASTER_SITES=	http://sofia.nmsu.edu/~mleisher/Software/gbdfed/

MAINTAINER=	lichray@gmail.com
COMMENT=	A GTK2 bitmap font editor

LICENSE=	MIT

USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		gbdfed.1
PLIST_FILES=	bin/gbdfed

NO_STAGE=	yes
.include <bsd.port.mk>
