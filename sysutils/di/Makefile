# Created by: Brad Lanam <bll@gentoo.com>
# $FreeBSD$

PORTNAME=	di
PORTVERSION=	4.35
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/ \
		http://www.cyberbotx.com/di/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Disk Information Utility

MAKE_ENV+=	prefix="${PREFIX}"

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB=	NLS=""
.else
PLIST_SUB=	NLS="@comment "
MAKE_ENV+=	DI_NO_NLS=T
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|zoneid_t|zoneId_t|g" ${WRKSRC}/C/di.c

.include <bsd.port.mk>
