# Ports collection makefile for:	sfs
# Date created:				2002-07-11
# Whom:					Michael Handler <handler@grendel.net>
#					Matthew Dodd <winter@jurai.net>
#
# $FreeBSD$
#

PORTNAME=	sfs
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.fs.net/sfswww/dist/

MAINTAINER=	handler@grendel.net
COMMENT=	Self-Certifying File System: A secure global network file system

PLIST_SUB=	SFS_VERSION=${PORTVERSION}

INFO=		sfs

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-sfsuser=sfs \
		--with-sfsgroup=sfs \
		--with-sfsdir=/var/spool/sfs \
		--with-etcdir=${PREFIX}/etc/sfs \
		--disable-uvfs

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

.if ${OSVERSION} > 500000
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4
CONFIGURE_ARGS+=--with-gmp=${PREFIX}
.else
CONFIGURE_ARGS+=--with-gmp=/usr
.endif

MAN1=	\
		dirsearch.1 \
		newaid.1 \
		rex.1 \
		sfsagent.1 \
		sfskey.1 \
		ssu.1

MAN5=	\
		sfs_config.5 \
		sfs_srp_params.5 \
		sfs_users.5 \
		sfsauthd_config.5 \
		sfscd_config.5 \
		sfsrwsd_config.5 \
		sfssd_config.5

MAN7=	\
		sfs.7

MAN8=	\
		funmount.8 \
		sfsauthd.8 \
		sfscd.8 \
		sfsrwsd.8 \
		sfssd.8 \
		vidb.8

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/sfscd.sh > ${WRKSRC}/sfscd.sh
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/sfssd.sh > ${WRKSRC}/sfssd.sh

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sfsauthd/upgradedb.pl ${PREFIX}/lib/sfs-${PORTVERSION}/upgradedb.pl
	${INSTALL_SCRIPT} ${WRKSRC}/sfscd.sh ${PREFIX}/etc/rc.d/sfscd.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/sfssd.sh ${PREFIX}/etc/rc.d/sfssd.sh.sample
	${MKDIR} ${PREFIX}/etc/sfs
	${INSTALL_DATA} ${FILESDIR}/etc-sfsrwsd_config.sample ${PREFIX}/etc/sfs/sfsrwsd_config.sample
	${MKDIR} ${PREFIX}/share/doc/sfs
	${INSTALL_DATA} ${FILESDIR}/share-doc-WELCOME ${PREFIX}/share/doc/sfs/WELCOME
	${INSTALL_DATA} ${FILESDIR}/share-doc-README ${PREFIX}/share/doc/sfs/README
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sfs/README.packageblurb
	${INSTALL_DATA} ${WRKSRC}/README.0.7-upgrade ${PREFIX}/share/doc/sfs/README.0.7-upgrade
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
