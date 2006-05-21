# New ports collection makefile for:	gorilla
# Date created:				2006-02-11
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	gorilla
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.fpx.de/fp/Software/Gorilla/download/

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Password Gorilla is cross-platform Password Manager

BUILD_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${USE_TK}
LIB_DEPENDS=	itcl.3:${PORTSDIR}/lang/itcl
RUN_DEPENDS=	${LOCALBASE}/lib/bwidget/init.tcl:${PORTSDIR}/x11-toolkits/bwidget

USE_TCL=	yes
USE_TK=		yes
GNU_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/gorilla
	@${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/lib/gorilla
	${TAR} -C ${WRKSRC} -cf - blowfish pics pwsafe twofish | \
		${TAR} -C ${PREFIX}/lib/gorilla --unlink -xf -
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gorilla
	@${CHMOD} ugo+x ${PREFIX}/bin/gorilla

.include <bsd.port.mk>
