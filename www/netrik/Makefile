# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	netrik
# Date created:		2002-12-23
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netrik
PORTVERSION=	1.10.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	A text web browser, very ambitious, in active development

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_GMAKE=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		netrik.1
MAN5=		netrikrc.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.include <bsd.port.post.mk>
