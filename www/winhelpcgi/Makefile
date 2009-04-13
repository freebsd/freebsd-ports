# New ports collection makefile for:   winhelpcgi
# Date created:        3 May 2004
# Whom:                Robin Schoonover (endx7@users.sf.net)
#
# $FreeBSD$
#

PORTNAME=	winhelpcgi
PORTVERSION=	1.0r3
PORTREVISION=	2
CATEGORIES=	www textproc
MASTER_SITES=	http://www.herdsoft.com/ftp/
DISTNAME=	${PORTNAME}_1.0rc3-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A winhelp converter cgi program

LIB_DEPENDS=	wmf.2:${PORTSDIR}/graphics/libwmf

EXPIRATION_DATE=	2009-06-01

WRKSRC=		${WRKDIR}/${PORTNAME}-1.0rc3
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:14
USE_GETTEXT=		yes
USE_APACHE=		1.3
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
