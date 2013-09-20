# Created by: Dax Labrador <semprix@bsdmail.org>
# $FreeBSD$

PORTNAME=	unssh
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://www.semprixd.com/shares/ports/

MAINTAINER=	semprix@gmx.com
COMMENT=	Fast way to delete entries from OpenSSH known_hosts file

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
PLIST_FILES=	bin/unssh

NO_STAGE=	yes
do-install:
	@${INSTALL} -d ${PREFIX}/bin
	@${CP} ${WRKSRC}/unssh.sh ${PREFIX}/bin/unssh
	@${CHMOD} ${BINMODE} ${PREFIX}/bin/unssh

.include <bsd.port.mk>
