# Created by: matthias.andree@gmx.de
# $FreeBSD$

PORTNAME=	cvsupchk
PORTVERSION=	19990209
PORTREVISION=	2
CATEGORIES=	net
DISTFILES=

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Check a CVSup directory hierarchy against the checkouts file

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/cvsup-without-gui:extract
FETCH_DEPENDS:=	${EXTRACT_DEPENDS}

PLIST_FILES=	bin/cvsupchk
PORTDOCS=	*

USE_PYTHON=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

get_src=	${MAKE} -C ${PORTSDIR}/net/cvsup-without-gui -V WRKSRC

do-extract:
	${MKDIR} ${WRKSRC}
	${SED} 's:^#!/usr/local/bin/python:#!${PYTHON_CMD}:' <$$(${get_src})/contrib/cvsupchk/cvsupchk >${WRKSRC}/cvsupchk

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cvsupchk ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} $$(${get_src})/contrib/cvsupchk/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
