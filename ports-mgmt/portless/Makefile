# Created by: Martin Kammerhofer
# $FreeBSD$

PORTNAME=	portless
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	mkamm@gmx.net
COMMENT=	Quick display of files inside the FreeBSD ports tree

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		shebangfix
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/portless man/man1/portless.1.gz
SHEBANG_FILES=	portless

post-extract:
	${SED} -e 's;@BASH@;/bin/bash;g' \
		${FILESDIR}/portless.sh > ${WRKSRC}/portless

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portless ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/portless.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
