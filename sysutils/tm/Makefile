# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tm
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://vicerveza.homeunix.net/~viric/soft/tm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal mixer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_ENV=	LINUX_LIBS=-lutil

PLIST_FILES=	bin/tm
PORTDOCS=	ChangeLog DOCS index.html

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/web/index.html ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e 's|$$^|$${.ALLSRC}|;/^GLIBCFLAGS/d;/^CFLAGS/d;\
		/^CC/d;/^ifeq/,/^endif/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|pty.h|libutil.h|' ${WRKSRC}/app_term.c
	@${ECHO_CMD} '#include <string.h>' >> ${WRKSRC}/main.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
