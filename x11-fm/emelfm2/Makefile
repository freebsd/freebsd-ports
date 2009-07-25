# New ports collection makefile for:   emelfm2
# Date created:        01 Novemeber 2003
# Whom:                Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	emelfm2
PORTVERSION=	0.6.2
CATEGORIES=	x11-fm
MASTER_SITES=	http://emelfm2.net/rel/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	The gtk2 port of emelfm, a fast graphical filemanager

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV=	LDFLAGS="${LDFLAGS}" DOC_DIR="${DOCSDIR}/" MAN_DIR="${MAN1PREFIX}/man/man1"
MAN1=		emelfm2.1

OPTIONS=	DEBUG	"Enable debugging messages" off \
		GAMIN 	"Enable Gamin for file monitoring" off \
		FAM	"Enable FAM for file monitoring" off \
		THUMB	"Enable the thumbnail plugin" off \
		TRACKER	"Enable the tracker plugin" off \
		HAL	"Enable HAL support" off \
		NLS	"Enable gettext support" on

DOCFILES=	ACTIONS CONFIGURATION CREDITS GPL HACKING INSTALL LGPL NEWS \
		README SPEC TODO USAGE WARNING

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
MAK_ENV+=	DEBUG=1
.endif

.if defined(WITH_GAMIN) && defined(WITH_FAM)
BROKEN=	WITH_GAMIN and WITH_FAM cannot be enabled at the same time for this port
.endif

.if defined(WITH_GAMIN)
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
MAKE_ENV+=	USE_GAMIN=1
.endif

.if defined(WITH_FAM)
USE_FAM=	yes
WANT_FAM_SYSTEM=fam
MAKE_ENV+=	USE_FAM=1
.endif

.if defined(WITH_THUMB)
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp
MAKE_ENV+=	WITH_THUMB=1
PLIST_SUB+=	THUMB=""
.else
PLIST_SUB+=	THUMB="@comment "
.endif

.if defined(WITH_TRACKER)
MAKE_ENV+=	WITH_TRACKER=1
PLIST_SUB+=	TRACKER=""
.else
PLIST_SUB+=	TRACKER="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
INSTALL_TARGET+=install_i18n
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if defined (WITH_HAL)
MAKE_ENV+=	WITH_HAL=1
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
