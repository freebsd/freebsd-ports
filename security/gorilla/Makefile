# New ports collection Makefile for:	gorilla
# Date created:				2006-02-11
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	gorilla
PORTVERSION=	1.5.3.1
DISTVERSIONSUFFIX=	c05eb4e
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.bayofrum.net/dist/gorilla/ \
		http://cerberus.bayofrum.net/dist/gorilla/
DISTNAME=	zdia-${PORTNAME}-v${DISTVERSION}-0-g${DISTVERSIONSUFFIX}

MAINTAINER=	utisoft@gmail.com
COMMENT=	Password Gorilla is a cross-platform Password Manager

RUN_DEPENDS=	${LOCALBASE}/lib/bwidget/init.tcl:${PORTSDIR}/x11-toolkits/bwidget \
		itcl>=3.4:${PORTSDIR}/lang/itcl \
		wish:${PORTSDIR}/x11-toolkits/tk-wrapper

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/zdia-${PORTNAME}-${DISTVERSIONSUFFIX}
USE_TCL_RUN=	85+
USE_TK=		85+
NO_BUILD=	yes
SUB_FILES=	gorilla
SUB_LIST=	WISH=wish

do-install:
	@${MKDIR} ${PREFIX}/lib/gorilla
	@${INSTALL_SCRIPT} ${WRKSRC}/sources/*.tcl ${PREFIX}/lib/gorilla
	${TAR} -C ${WRKSRC}/sources -cf - blowfish pics pwsafe twofish sha1 | \
		${TAR} -C ${PREFIX}/lib/gorilla --unlink -xf -
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gorilla
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/blowfish/*.tcl
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/pwsafe/*.tcl
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/twofish/*.tcl
	@${CHMOD} ugo+rx ${PREFIX}/lib/gorilla/sha1/*.tcl

.include <bsd.port.mk>
