# New ports collection makefile for:	srm
# Date created:				25 Oct 2000
# Whom:					Keith J. Jones <kjones@antihackertoolkit.com>
#
# $FreeBSD$
#

PORTNAME=	srm
PORTVERSION=	1.2.8
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	srm

MAINTAINER=	kjones@antihackertoolkit.com
COMMENT=	Secure rm, a utility which destroys file contents before unlinking

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=	15

MAN1=		srm.1
PLIST_FILES=	bin/srm

.include <bsd.port.mk>
