# New ports collection makefile for:   winhelpcgi
# Date created:        3 May 2004
# Whom:                Robin Schoonover (endx7@users.sf.net)
#
# $FreeBSD$
#

PORTNAME=	winhelpcgi
PORTVERSION=	0.93.1
CATEGORIES=	www textproc
MASTER_SITES=	http://www.herdsoft.com/ftp/
DISTNAME=	${PORTNAME}_0.93-1

MAINTAINER=	endx7@users.sf.net
COMMENT=	A winhelp converter cgi program

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_AUTOMAKE_VER=	14
AUTOMAKE_ARGS=	--add-missing
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

# get rid of symlinks
pre-patch:
	(cd ${WRKSRC}; ${RM} INSTALL install-sh mkinstalldirs missing COPYING)

post-build:
	@${CAT} ${PKGDIR}/pkg-message | ${SED} -e 's:%%PREFIX%%:${PREFIX}:' > ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/winhelpcgi/winhelpcgi/winhelpcgi.cgi ${PREFIX}/bin

.include <bsd.port.post.mk>
