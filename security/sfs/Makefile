# Ports collection makefile for:	sfs
# Date created:				2002-07-11
# Whom:					Michael Handler <handler@grendel.net>
#					Matthew Dodd <winter@jurai.net>
#
# $FreeBSD$
#

PORTNAME=	sfs
PORTVERSION=	0.7.2
PORTREVISION=	9
CATEGORIES=	security net
MASTER_SITES=	http://www.fs.net/sfswww/dist/

MAINTAINER=	malus.x@gmail.com
COMMENT=	Self-Certifying File System: A secure global network file system

PLIST_SUB=	SFS_VERSION=${PORTVERSION}

INFO=		sfs

USE_RC_SUBR=	sfscd sfssd

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-sfsuser=sfs \
		--with-sfsgroup=sfs \
		--with-sfsdir=/var/spool/sfs \
		--with-etcdir=${PREFIX}/etc/sfs \
		--disable-uvfs \
		--with-gmp=${LOCALBASE}

LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		nfsmounter component fails to execute correctly on ${ARCH} systems
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
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(C|h)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/template get/get/'

	@${REINPLACE_CMD} -e 's/authsess::\(authsess\)/\1/' \
		${WRKSRC}/agent/agent.h

	@${REINPLACE_CMD} -e 's/\(u_int32_t val\)/\1 = 0/' \
		${WRKSRC}/arpc/xdrmisc.C

	@${REINPLACE_CMD} -e 's/\(errorbuf = \)""/\1const_cast<char *> ("")/' \
		${WRKSRC}/async/parseopt.C

	@${REINPLACE_CMD} -e 's/, \(&dummy_len\)/, (socklen_t *)\1/' \
		${WRKSRC}/rex/connect.c

	@${REINPLACE_CMD} -e 's/, \(&reslen\)/, (socklen_t *)\1/' \
		${WRKSRC}/rex/listen.c

	@${REINPLACE_CMD} -e 's/ptyclient::\(ptyclient\)/\1/' \
		${WRKSRC}/rex/ptyd.C

	@${REINPLACE_CMD} -e 's/\("ptyd"\)/const_cast<char *> (\1)/' \
		${WRKSRC}/rex/rexd.C

	@${REINPLACE_CMD} -e 's/, &sn/, (socklen_t *)\&sn/' \
		${WRKSRC}/rex/uasync.c

	@${REINPLACE_CMD} -e \
		's/\(\\"" << cp->id << "\\"\)/const_cast<char *> (\1)/' \
		${WRKSRC}/rpcc/gencfile.C

	@${REINPLACE_CMD} -e 's/= fhextra =/=/' ${WRKSRC}/sfscd/ctlnode.C

	@${REINPLACE_CMD} -e 's/\("-c"\)/const_cast<char *> (\1)/' \
		${WRKSRC}/sfsmisc/agentmisc.C

	@${REINPLACE_CMD} -e 's/\("localhost"\)/const_cast<char *> (\1)/' \
		${WRKSRC}/sfsrwsd/client.C

post-configure:
	@${REINPLACE_CMD} -e 's/^\(NOPAGING =\).*$$/(\1)/' \
		${WRKSRC}/sfsrwcd/Makefile

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sfsauthd/upgradedb.pl ${PREFIX}/lib/sfs-${PORTVERSION}/upgradedb.pl
	${MKDIR} ${PREFIX}/etc/sfs
	${INSTALL_DATA} ${FILESDIR}/etc-sfsrwsd_config.sample ${PREFIX}/etc/sfs/sfsrwsd_config.sample
	${MKDIR} ${PREFIX}/share/doc/sfs
	${INSTALL_DATA} ${FILESDIR}/share-doc-WELCOME ${PREFIX}/share/doc/sfs/WELCOME
	${INSTALL_DATA} ${FILESDIR}/share-doc-README ${PREFIX}/share/doc/sfs/README
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sfs/README.packageblurb
	${INSTALL_DATA} ${WRKSRC}/README.0.7-upgrade ${PREFIX}/share/doc/sfs/README.0.7-upgrade
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
