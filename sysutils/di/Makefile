# Created by: Brad Lanam <bll@gentoo.com>
# $FreeBSD$

PORTNAME=	di
PORTVERSION=	4.34
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Disk Information Utility

MAKE_ENV+=	prefix="${PREFIX}"
MAKE_JOBS_SAFE=	yes

MAN1=		di.1

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
PLIST_SUB=	NLS="@comment "
MAKE_ENV+=	DI_NO_NLS=T
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|zoneid_t|zoneId_t|g" ${WRKSRC}/C/di.c

.include <bsd.port.mk>
