# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

BUILD_DEPENDS=	${LOCALBASE}/lib/libgdc.a:${PORTSDIR}/graphics/gdchart
LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

DBDIR?=		/var/db

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB+=	DBDIR=${DBDIR}
CONFIGURE_ENV=	LIBS="-lcrypto -L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-ossl-root=${OPENSSLBASE} \
		--with-gdchart-root=${LOCALBASE}
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		CAT="${CAT}" \
		OPTIONS="${OPTIONS}" \
		REALCURDIR="${.CURDIR}"

MAN8=		ntop.8

.include <bsd.port.pre.mk>

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.sh

post-patch:
	@${REINPLACE_CMD} -e "s,-lgdchart,-lgdc,g" \
		-e "s,-lglib,-lglib12,g" ${WRKSRC}/configure

post-install:
	@${MKDIR} ${DBDIR}/ntop
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} -e "s#%%PREFIX%%#${PREFIX}#g" \
		-e "s#%%LOGDIR%%#${LOGDIR}#g" ${FILESDIR}/ntop.sh > \
		${WRKDIR}/ntop.sh
	@${INSTALL_DATA} ${WRKDIR}/ntop.sh ${PREFIX}/etc/rc.d
.if !defined(BATCH)
	@${SED} "s,%%LOCALBASE%%,${LOCALBASE},g" < ${PKGMESSAGE}
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.post.mk>
