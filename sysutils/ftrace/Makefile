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

GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS} -DPIC -fPIC -D_REENTRANT -I." \
		LDFLAGS="-shared"
INSTALLS_SHLIB=	yes

PLIST_FILES=	bin/ftrace lib/libftrace.so
PORTDOCS=	COPYING README TODO ChangeLog

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/ftrace ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/libftrace.so ${PREFIX}/lib
		${MKDIR} ${DOCSDIR}
		cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.mk>
