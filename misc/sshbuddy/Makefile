# New ports collection makefile for:	sshbuddy
# Date created:		26 September 1999
# Whom:			Dan Moschuk <dan@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sshbuddy
PORTVERSION=	1.05
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sundilla.net/pub/linux/apps/sshbuddy/beta1.05/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar

MAINTAINER=	dan@freebsd.org

RUN_DEPENDS=	expectk:${PORTSDIR}/lang/expect

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/beta1.05

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sshbuddy.expk ${PREFIX}/bin/sshbuddy

.include <bsd.port.mk>
