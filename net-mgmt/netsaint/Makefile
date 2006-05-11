# New ports collection makefile for:	netsaint
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint
PORTVERSION=	0.0.7
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://netsaint.sourceforge.net/download/ \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=dwcjr/:local
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} netsaint-graphics.tar.gz:local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely powerful network monitoring system

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/netsaint/check_netsaint:${PORTSDIR}/net-mgmt/netsaint-plugins

DEPRECATED=	Now developed as Nagios, see net-mgmt/nagios port

USE_PERL5=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-command-user=netsaint \
		--with-command-grp=www \
		--with-gd-lib=${LOCALBASE}/lib \
		--with-gd-inc=${LOCALBASE}/include \
		--with-netsaint-user=netsaint \
		--with-netsaint-grp=netsaint \
		--sbindir=${PREFIX}/share/netsaint/sbin \
		--libexecdir=${PREFIX}/libexec/netsaint \
		--datadir=${PREFIX}/share/netsaint \
		--sysconfdir=${PREFIX}/etc/netsaint \
		--localstatedir=${PREFIX}/var/netsaint
INSTALL_TARGET=	all install config install-config install-daemoninit install-commandmode

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
CONFIGURE_ARGS+=--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-inc=${LOCALBASE}/include/mysql \
		--with-mysql-xdata
.endif

.if defined(WITH_POSTGRES)
USE_PGSQL=	YES
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/lib \
		--with-pgsql-inc=${LOCALBASE}/include \
		--with-pgsql-xdata
.endif

pre-fetch:
	@${SH} ${SCRIPTDIR}/checkps

post-patch:
.if defined(WITH_POSTGRES)
	@${REINPLACE_CMD} -e 's,pgsql/,,' ${WRKSRC}/xdata/x[cers]ddb.c
.endif

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for i in bsd_logofullsize.gif bsd_sblogo.gif
	${INSTALL_DATA} ${WRKDIR}/netsaint-0.0.7b6/html/images/$i ${PREFIX}/share/${PORTNAME}/images/
.endfor

.include <bsd.port.mk>
