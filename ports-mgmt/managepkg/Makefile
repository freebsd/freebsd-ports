# Created by: Andreas Fehlner <fehlner@gmx.de>
# $FreeBSD$

PORTNAME=	managepkg
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.cul.de/data/\
		http://home.arcor.de/fehlner/fbsd_ports/\
		http://home.arcor.de/teambushido/fbsd_ports/
EXTRACT_SUFX=	.gz

MAINTAINER=	fehlner@gmx.de
COMMENT=	Script for maintaining ports

BROKEN=		unfetchable
# Any ideas for a better comment?

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/managepkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
