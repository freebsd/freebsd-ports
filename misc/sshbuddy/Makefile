# New ports collection makefile for:	sshbuddy
# Version required: 	1.0
# Date created:		26 September 1999
# Whom:			Dan Moschuk <dan@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	sshbuddy1.02
PKGNAME=	sshbuddy-1.02
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sundilla.net/pub/linux/apps/sshbuddy/beta1.02/
EXTRACT_SUFX=	.tar

MAINTAINER=	dan@freebsd.org

RUN_DEPENDS=	expectk:${PORTSDIR}/lang/expect
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80 \
		tk80.1:${PORTSDIR}/x11-toolkits/tk80

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/beta1.02

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sshbuddy.expk ${PREFIX}/bin/sshbuddy

.include <bsd.port.mk>
