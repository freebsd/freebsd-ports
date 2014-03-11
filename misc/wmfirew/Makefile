# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmfirew
PORTVERSION=	0.20
PORTREVISION=	3
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://web.novalis.org/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that shows fireworks in action

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
PLIST_FILES=	bin/wmfirew
WRKSRC=	${WRKDIR}/${PORTNAME}.app/${PORTNAME}
USE_GMAKE=	yes
USE_XORG=	xpm

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
	    's|^void main|int main|' ${WRKSRC}/wmfirew.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)

.include <bsd.port.mk>
