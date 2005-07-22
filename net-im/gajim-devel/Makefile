# New ports collection makefile for:	gajim
# Date created:				27 April 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	0.7.1
CATEGORIES=	net
MASTER_SITES=	http://www.gajim.org/downloads/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Gajim is a Jabber client based on a plugin system

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2

USE_X_PREFIX=	yes
USE_PYTHON=	2.3+
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	pygtk2

MAKE_ENV+=	PY_CFLAGS=-I${PYTHON_INCLUDEDIR} \
		PY_PREFIX=${LOCALBASE} \
		CC=${CC} LDFLAGS=-L${LOCALBASE}/lib

MAN1=		gajim.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX.*=.*||; s|^DESTDIR.*=.*||; s|share/man|man|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|CFLAGS =|CFLAGS +=|; s|LDFLAGS =|LDFLAGS +=|; \
		 s|-I/usr/include/python\$$(PYTHONVER)|$$(PY_CFLAGS)|' \
		${WRKSRC}/src/Makefile ${WRKSRC}/src/common/Makefile

.include <bsd.port.mk>
