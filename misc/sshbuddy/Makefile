# New ports collection makefile for:	sshbuddy
# Date created:		26 September 1999
# Whom:			Dan Moschuk <dan@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sshbuddy
PORTVERSION=	1.05
CATEGORIES=	misc
MASTER_SITES=	http://www.linuxmafia.com/pub/linux/security/sshbuddy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and small GUI utility to manage ssh sessions

RUN_DEPENDS=	expectk:${PORTSDIR}/lang/expect

NO_BUILD=	yes
PLIST_FILES=	bin/sshbuddy

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sshbuddy.expk ${PREFIX}/bin/sshbuddy

.include <bsd.port.mk>
