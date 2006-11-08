# New ports collection makefile for:	cvsupchk
# Date created:				07 Nov 2005
# Whom:					matthias.andree@gmx.de
#
# $FreeBSD$
#

PORTNAME=	cvsupchk
PORTVERSION=	19990209
PORTREVISION=	1
CATEGORIES=	net
DISTFILES=

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Check a CVSup directory hierarchy against the checkouts file

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/cvsup:extract

PLIST_FILES=	bin/cvsupchk
PORTDOCS=	*

USE_PYTHON=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

src!=		cd ${PORTSDIR}/net/cvsup && make -V WRKSRC

do-extract:
	${MKDIR} ${WRKSRC}
	${SED} 's:^#!/usr/local/bin/python:#!${PYTHON_CMD}:' <${src}/contrib/cvsupchk/cvsupchk >${WRKSRC}/cvsupchk

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cvsupchk ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${src}/contrib/cvsupchk/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
