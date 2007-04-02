# New ports collection makefile for:	gorilla
# Date created:				2006-02-11
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	gorilla
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.fpx.de/fp/Software/Gorilla/download/

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Password Gorilla is cross-platform Password Manager

LIB_DEPENDS=	itcl.3:${PORTSDIR}/lang/itcl
RUN_DEPENDS=	${LOCALBASE}/lib/bwidget/init.tcl:${PORTSDIR}/x11-toolkits/bwidget

USE_TCL_RUN=	yes
USE_TK=		yes
GNU_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/gorilla
	@${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/gorilla
	${TAR} -C ${WRKSRC} -cf - blowfish pics pwsafe twofish sha1 | \
		${TAR} -C ${PREFIX}/lib/gorilla --unlink -xf -
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gorilla
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/blowfish/*.tcl
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/pwsafe/*.tcl
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/twofish/*.tcl
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/sha1/*.tcl

.include <bsd.port.mk>
