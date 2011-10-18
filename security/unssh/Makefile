# New ports collection makefile for:	unssh
# Date created:				30 July 2009
# Whom:					Dax Labrador <semprix@bsdmail.org>
#
# $FreeBSD$
#

PORTNAME=	unssh
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://www.semprixd.com/shares/ports/

MAINTAINER=	semprix@gmx.com
COMMENT=	Fast way to delete entries from OpenSSH known_hosts file

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
PLIST_FILES=	bin/unssh

do-install:
	@${INSTALL} -d ${PREFIX}/bin
	@${CP} ${WRKSRC}/unssh.sh ${PREFIX}/bin/unssh
	@${CHMOD} ${BINMODE} ${PREFIX}/bin/unssh

.include <bsd.port.mk>
