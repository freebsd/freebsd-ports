# New ports collection makefile for:	freeipmi
# Date created:				20/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#

PORTNAME=	freeipmi
PORTVERSION=	0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.californiadigital.com/pub/${PORTNAME}/download/${PORTVERSION}/

PATCH_SITES=	ftp://ftp.riss-telecom.ru/pub/patches/
PATCHFILES=	${DISTNAME}-fbsd.diff

MAINTAINER=	frolov@riss-telecom.ru
COMMENT=	Library and tools to support IPMI-capable hardware

LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
BUILD_DEPENDS+=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone

USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NOT_FOR_ARCHS=	ia64 sparc64 alpha
PLIST_SUB+=	SHLIBVER=${SHLIBVER} RUNDIR=${RUNDIR} LOGDIR=${LOGDIR}
MAN1+=		bmc-config.1 bmc-info.1 fish.1 sel.1 sensors.1
MAN5+=		ipmipower.conf.5
MAN8+=		bmc-watchdog.8 ipmipower.8 ipmiping.8 rmcpping.8
INFO+=		freeipmi
PORTDOCS=	*
PKGDEINSTALL=	${PKGINSTALL}

OPTIONS+=	IOPERM "Use i386_set_ioperm(2) instead of io(4)" off

SHLIBVER=	1

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -largp
.if defined(WITH_IOPERM)
CPPFLAGS+=	-DUSE_IOPERM
.endif
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
