# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	redet
PORTVERSION=	8.26
CATEGORIES=	textproc tk
MASTER_SITES=	http://www.billposer.org/Software/Downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual regexp development and execution

RUN_DEPENDS=	iwidgets>0:x11-toolkits/iwidgets

NO_BUILD=	yes
NO_ARCH=	yes
USES=		tk:run tar:bzip2

PORTDOCS=	AUTHORS COPYING CREDITS LICENSE NEWS README-General ChangeLog
PLIST_FILES=	bin/redet \
		man/man1/redet.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s@exec wish@exec ${WISH}@" ${WRKSRC}/redet.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/redet.tcl ${STAGEDIR}${PREFIX}/bin/redet
	${INSTALL_MAN} ${WRKSRC}/redet.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
