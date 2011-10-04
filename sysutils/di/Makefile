# New ports collection makefile for:	di
# Date created:			31 August 2002
# Whom:				Brad Lanam <bll@gentoo.com>
#
# $FreeBSD$
#

PORTNAME=	di
PORTVERSION=	4.29
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Disk Information Utility

MAN1=		di.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
PLIST_SUB=	NLS="@comment "
MAKE_ENV+=	DI_NO_NLS=T
.endif

MAKE_ENV+=	prefix="${PREFIX}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|zoneid_t|zoneId_t|g" ${WRKSRC}/C/di.c

.include <bsd.port.post.mk>
