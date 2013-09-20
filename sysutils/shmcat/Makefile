# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	shmcat
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Simple tool that dumps System V shared memory segments

USE_BZIP2=	yes
USEs=		iconv
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS

MAN1=		shmcat.1 \
		ftok.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
MANLANG=	"" de
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
