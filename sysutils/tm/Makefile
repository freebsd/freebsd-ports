# New ports collection makefile for:	tm
# Date created:		18 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tm
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://vicerveza.homeunix.net/~viric/soft/tm/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal mixer

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ChangeLog DOCS index.html
MAKE_ENV=	LINUX_LIBS=-lutil

post-extract:
	@${MV} ${WRKSRC}/web/index.html ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e 's|$$^|$${.ALLSRC}|;/^GLIBCFLAGS/d;/^CFLAGS/d;\
		/^CC/d;/^ifeq/,/^endif/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|pty.h|libutil.h|' ${WRKSRC}/app_term.c
	@${ECHO_CMD} '#include <string.h>' >> ${WRKSRC}/main.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
