# New ports collection makefile for:   winhelpcgi
# Date created:        3 May 2004
# Whom:                Robin Schoonover (endx7@users.sf.net)
#
# $FreeBSD$
#

PORTNAME=	winhelpcgi
PORTVERSION=	1.0r3
CATEGORIES=	www textproc
MASTER_SITES=	http://www.herdsoft.com/ftp/
DISTNAME=	${PORTNAME}_1.0rc3-1

MAINTAINER=	robin.schoonover@gmail.com
COMMENT=	A winhelp converter cgi program

LIB_DEPENDS=	wmf.2:${PORTSDIR}/graphics/libwmf

WRKSRC=		${WRKDIR}/${PORTNAME}-1.0rc3
GNU_CONFIGURE=	yes
USE_AUTOMAKE_VER=	14
USE_GETTEXT=		yes
USE_APACHE=		yes
PKGMESSAGE=	${WRKDIR}/pkg-message

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
