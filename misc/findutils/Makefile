# Created by: Robert Withrow <witr@rwwa.com>
# $FreeBSD$

PORTNAME=	findutils
PORTVERSION=	4.5.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	findutils
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	aehlig@linta.de
COMMENT=	GNU find utilities

USES+=		charsetfix
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.sig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GMAKE=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

CONFIGURE_ARGS+=	--program-prefix=g --localstatedir=${LOCALSTATEDIR}
MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

INFO=		find find-maint
MAN1=		gfind.1 gxargs.1 glocate.1 gupdatedb.1 goldfind.1
MAN5=		glocatedb.5

LOCALSTATEDIR?=	/var/db

.include <bsd.port.mk>
