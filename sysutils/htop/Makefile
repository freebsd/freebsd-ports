# New ports collection makefile for:	htop
# Date created:		27 August 2007
# Whom:			Tony Shadwick <tshadwick@oss-solutions.com>
#
# $FreeBSD$
#

PORTNAME=	htop
PORTVERSION=	0.6.6
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	tshadwick@oss-solutions.com
COMMENT=	A better top(1) - interactive process viewer

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-proc=/compat/linux/proc
MAN1=	htop.1

pre-configure:
	@[ -f /compat/linux/proc/stat ] || { ${CAT} ${PKGMESSAGE}; ${FALSE}; }

.include <bsd.port.mk>
