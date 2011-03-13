# New ports collection makefile for:   ftrace
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ftrace
PORTVERSION=	0.9b
CATEGORIES=	sysutils
MASTER_SITES=	http://software.senko.net/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A file modification/creation watcher

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS} -DPIC -fPIC -D_REENTRANT -I." \
		LDFLAGS="-shared"
USE_LDCONFIG=	yes

PLIST_FILES=	bin/ftrace lib/libftrace.so
PORTDOCS=	COPYING README TODO ChangeLog

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/ftrace ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/libftrace.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
