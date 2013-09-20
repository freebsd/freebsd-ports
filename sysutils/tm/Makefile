# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tm
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://vicerveza.homeunix.net/~viric/soft/tm/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal mixer

LICENSE=	GPLv2

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ChangeLog DOCS index.html
MAKE_ENV=	LINUX_LIBS=-lutil

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-extract:
	@${MV} ${WRKSRC}/web/index.html ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e 's|$$^|$${.ALLSRC}|;/^GLIBCFLAGS/d;/^CFLAGS/d;\
		/^CC/d;/^ifeq/,/^endif/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|pty.h|libutil.h|' ${WRKSRC}/app_term.c
	@${ECHO_CMD} '#include <string.h>' >> ${WRKSRC}/main.h

.include <bsd.port.options.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
