# Created by: Keith J. Jones <kjones@antihackertoolkit.com>
# $FreeBSD$

PORTNAME=	srm
PORTVERSION=	1.2.11
CATEGORIES=	security sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kjones@antihackertoolkit.com
COMMENT=	Secure rm, a utility which destroys file contents before unlinking

CONFLICTS=	secure_delete-[0-9]*
USE_XZ=		yes

GNU_CONFIGURE=		yes

MAN1=		srm.1
PLIST_FILES=	bin/srm

NO_STAGE=	yes
.include <bsd.port.mk>
