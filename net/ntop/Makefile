# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	2.0.99.r2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://luca.ntop.org/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.r|-rc|}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org

# Besides the required dependencies listed here, this port can optionally
# make use of sysutils/lsof and security/nmap if installed.
BUILD_DEPENDS=	${LOCALBASE}/lib/libgdc.a:${PORTSDIR}/graphics/gdchart
RUN_DEPENDS=	${LOCALBASE}/lib/libgdc.a:${PORTSDIR}/graphics/gdchart
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

# ntop will store its runtime database files in ${DBDIR}/ntop/
DBDIR?=		/var/db

# The default startup script in ${LOCALBASE}/etc/rc.d will invoke
# with a flag to force it to log to ${LOGDIR}
LOGDIR?=	/var/log

WRKSRC=		${WRKDIR}/RC2/${PORTNAME}
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB+=	DBDIR=${DBDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-gdbm-root=${LOCALBASE} \
		--with-gdchart-root=${LOCALBASE}

.if !defined(WITHOUT_TCPWRAP)
CONFIGURE_ARGS+=	--enable-tcpwrap
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400014
LIB_DEPENDS+=	ssl.3:${PORTSDIR}/security/openssl
CONFIGURE_ARGS+=	--with-ossl-root=${LOCALBASE}
.endif

MAN1=		intop.1
MAN8=		ntop.8

# Remove included dependencies as a precaution against polluting the
# configuration.  Not strictly necessary.
pre-configure:
	@ ${RM} -rf ${WRKDIR}/RC2/gdchart*

post-configure:
	@ ${SED} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
	  pkg-message > ${PKGMESSAGE}

post-install:
	@ ${MKDIR} ${DBDIR}/ntop
	@ ${MKDIR} ${PREFIX}/etc/rc.d
	@ ${SED} -e "s#%%PREFIX%%#${PREFIX}#g" \
	  -e "s#%%LOGDIR%%#${LOGDIR}#g" ${FILESDIR}/ntop.sh > \
	  ${WRKDIR}/ntop.sh
	@ ${INSTALL_DATA} ${WRKDIR}/ntop.sh ${PREFIX}/etc/rc.d
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
