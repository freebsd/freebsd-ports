# Created by: FreeBSD GNOME Team
# $FreeBSD$
#   $MCom: ports/sysutils/pessulus/Makefile,v 1.30 2010/11/17 11:53:24 kwm Exp $

PORTNAME=	pessulus
PORTVERSION=	2.30.4
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lockdown editor for GNOME

OPTIONS_DEFINE=	DOCS

USES=		gettext gmake python tar:bzip2
USE_GNOME=	gnomeprefix intlhack pygnome2 pygnomedesktop
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS COPYING ChangeLog HACKING \
		MAINTAINERS NEWS README TODO

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
