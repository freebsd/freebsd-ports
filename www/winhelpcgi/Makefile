# New ports collection makefile for:   winhelpcgi
# Date created:        3 May 2004
# Whom:                Robin Schoonover (endx7@users.sf.net)
#
# $FreeBSD$
#

PORTNAME=	winhelpcgi
PORTVERSION=	0.99
CATEGORIES=	www textproc
MASTER_SITES=	http://www.herdsoft.com/ftp/
DISTNAME=	${PORTNAME}_0.99-3

MAINTAINER=	endx7@users.sf.net
COMMENT=	A winhelp converter cgi program

LIB_DEPENDS=	wmf.2:${PORTSDIR}/graphics/libwmf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_AUTOMAKE_VER=	14
USE_GETTEXT=		yes
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-patch:
	(cd ${WRKSRC}; ${TOUCH} config.h)

post-build:
	@${CAT} ${PKGDIR}/pkg-message | ${SED} -e 's:%%PREFIX%%:${PREFIX}:' > ${PKGMESSAGE}

do-install:
	${MKDIR} ${PREFIX}/www/winhelpcgi
	${INSTALL_PROGRAM} ${WRKSRC}/winhelpcgi/winhelpcgi.cgi ${PREFIX}/www/winhelpcgi

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
