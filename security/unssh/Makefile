# Created by: Dax Labrador <semprix@bsdmail.org>
# $FreeBSD$

PORTNAME=	unssh
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://www.semprixd.com/shares/ports/

MAINTAINER=	semprix@gmx.com
COMMENT=	Fast way to delete entries from OpenSSH known_hosts file

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/unssh
SHEBANG_FILES=	unssh.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/unssh.sh ${STAGEDIR}${PREFIX}/bin/unssh

.include <bsd.port.mk>
