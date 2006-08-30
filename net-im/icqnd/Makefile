# New ports collection makefile for:	icqnd
# Date Created:				29 Ago 2006
# Whom:					Rodrigo Graeff <delphus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	icqnd
PORTVERSION=	0.1.9.5
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	delphus@gmail.com
COMMENT=	GTK based LICQ GUI program

BUILD_DEPENDS=	licq:${PORTSDIR}/net-im/licq
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Doesn't build on 4.x
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
