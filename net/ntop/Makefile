# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ntop.org/pub/local/ntop/source/ \
		ftp://ftp.us.ntop.org/pub/ntop/source/ \
		ftp://ftp.au.ntop.org/pub/ntop/source/ \
		ftp://ftp.de.ntop.org/pub/ntop/source/ \
		ftp://ftp.fr.ntop.org/mirrors/networking/ntop/source/ \
		ftp://ftp.jp.ntop.org/pub/ntop/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org

# Besides the required dependencies listed here, this port can optionally
# make use of sysutils/lsof and security/nmap if installed.
BUILD_DEPENDS=	${LOCALBASE}/lib/libgdchart.a:${PORTSDIR}/graphics/gdchart
RUN_DEPENDS=	${LOCALBASE}/lib/libgdchart.a:${PORTSDIR}/graphics/gdchart
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

# ntop will store its database files in ${DBDIR}/ntop/
DBDIR?=		/var/db

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-gdbm-root=${LOCALBASE} \
		--with-gdchart-root=${LOCALBASE} \

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400014
LIB_DEPENDS+=	ssl.2:${PORTSDIR}/security/openssl
CONFIGURE_ARGS+=	--with-ossl-root=${LOCALBASE}
.endif

MAN1=		intop.1
MAN8=		ntop.8 ntop-rules.8

# Remove included dependencies as a precaution against polluting the
# configuration.  Not strictly necessary.
pre-configure:
	@ ${RM} -rf ${WRKDIR}/gdchart*

post-install:
	@ ${MKDIR} ${DBDIR}/ntop
	@ ${MKDIR} ${PREFIX}/etc/rc.d
	@ ${SED} -e "s#%%PREFIX%%#${PREFIX}#g" ${FILESDIR}/ntop.sh > \
	  ${WRKDIR}/ntop.sh
	@ ${INSTALL_SCRIPT} ${WRKDIR}/ntop.sh ${PREFIX}/etc/rc.d

.include <bsd.port.post.mk>
