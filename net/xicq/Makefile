# New ports collection makefile for:	xicq
# Date created:				29 June 1998
# Whom:					scrappy
#
# $FreeBSD$
#

PORTNAME=	xicq
PORTVERSION=	19980712
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://projekt.pinknet.cz/ftp/ICQ/linux/Xicq/
DISTNAME=	xicq-071298-snapshot.src

MAINTAINER=	scrappy@FreeBSD.org
COMMENT=	Xtropy's ICQ Client

WRKSRC=		${WRKDIR}/xicq-071298
USE_GCC=	2.95
USE_GMAKE=	yes
MAKE_ENV=	OPT="${CFLAGS}"

PLIST_FILES=	bin/xicq ${EXAMPLESDIR:S,^${PREFIX}/,,g}/contact ${EXAMPLESDIR:S,^${PREFIX}/,,g}/config
PLIST_DIRS=	${EXAMPLESDIR:S,^${PREFIX}/,,g}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/xicq/main ${PREFIX}/bin/xicq
		${MKDIR} ${EXAMPLESDIR}
.for file in contact config
		${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
