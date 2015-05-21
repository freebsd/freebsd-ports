# Created by: Shinsuke Matsui <smatsui@karashi.org>
# $FreeBSD$

PORTNAME=	tinytinyhttpd
PORTVERSION=	0.0.11
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/mattn/tinytinyhttpd/

MAINTAINER=	smatsui@karashi.org
COMMENT=	Tiny tiny httpd

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/tthttpd
SUB_FILES=	example.conf
PORTDOCS=	README example.conf ChangeLog
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tthttpd ${STAGEDIR}${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/example.conf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
