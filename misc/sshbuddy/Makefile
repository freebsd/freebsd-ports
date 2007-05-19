# New ports collection makefile for:	sshbuddy
# Date created:		26 September 1999
# Whom:			Dan Moschuk <dan@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sshbuddy
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://linuxmafia.com/pub/linux/security/sshbuddy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and small GUI utility to manage ssh sessions

RUN_DEPENDS=	expectk:${PORTSDIR}/lang/expect

NO_BUILD=	yes
PLIST_FILES=	bin/sshbuddy

.if defined(WITHOUT_X11)
BROKEN=		Broken dependency
.endif

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sshbuddy.expk ${PREFIX}/bin/sshbuddy

.include <bsd.port.mk>
