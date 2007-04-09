# Ports collection makefile for:  rsync
# Date created:			  Sat Aug 3, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	rsync
PORTVERSION=	2.6.9
CATEGORIES=	net ipv6
MASTER_SITES=	http://rsync.samba.org/ftp/%SUBDIR%/ \
		ftp://ftp.samba.org/pub/%SUBDIR%/ \
		ftp://sunsite.auc.dk/pub/unix/%SUBDIR%/  \
		ftp://ftp.sunet.se/pub/unix/admin/%SUBDIR%/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/rsync.samba.org/
MASTER_SITE_SUBDIR=	rsync

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A network file distribution/synchronization utility

USE_RC_SUBR=	rsyncd.sh
SUB_LIST=	NAME=rsyncd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --enable-ipv6  --mandir=${PREFIX}/man \
		--with-rsyncd-conf=${PREFIX}/etc/rsyncd.conf
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PATCH_STRIP=	-p1

.if !defined(NOPORTDOCS)
PORTDOCS=	NEWS README csprotocol.txt tech_report.tex
.endif

MAN1=		rsync.1
MAN5=		rsyncd.conf.5

OPTIONS=	POPT_PORT "Use popt from devel/popt instead of bundled one" off \
		TIMELIMIT "Time limit patch" on \
		FLAGSP "File system flags support patch, adds --flags" off \
		ACLSP "ACL support patch, adds --acls" off \
		SSH "Use SSH instead of RSH" on

.include <bsd.port.pre.mk>

.if defined(WITH_POPT_PORT)
LIB_DEPENDS+=	popt.0:${PORTSDIR}/devel/popt
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

.if !defined(WITHOUT_TIMELIMIT)
EXTRA_PATCHES+=	${WRKSRC}/patches/time-limit.diff
.endif

.if defined(WITH_FLAGSP)
EXTRA_PATCHES+=	${WRKSRC}/patches/flags.diff
.endif

.if defined(WITH_ACLSP)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patches-acls.diff ${WRKSRC}/patches/acls.diff
CONFIGURE_ARGS+=--enable-acl-support

.if defined(WITH_FLAGSP)
IGNORE=		can't be built: Flags and ACLs patches can't be both enabled at the same time. Please rerun 'make config' and disable one of them
.endif
.endif

.if defined(WITHOUT_SSH)
CONFIGURE_ARGS+=	--with-rsh=rsh
.endif

# guard against CFLAGS damage by MAKE_ENV
post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS|CONFIGUREDCFLAGS|' ${WRKSRC}/Makefile.in

pre-configure:
	@${REINPLACE_CMD} -e 's:/etc/:${PREFIX}/etc/:g'  \
		${WRKSRC}/rsync.h ${WRKSRC}/rsync.1 ${WRKSRC}/rsyncd.conf.5
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${WRKSRC}/rsync.h ${WRKSRC}/zlib/zutil.h

post-install:
	@${STRIP_CMD} ${DESTDIR}${PREFIX}/bin/rsync
	@${INSTALL_DATA} ${FILESDIR}/rsyncd.conf.sample ${DESTDIR}${PREFIX}/etc/
	@[ -f ${DESTDIR}${PREFIX}/etc/rsyncd.conf ] || \
		${CP} ${DESTDIR}${PREFIX}/etc/rsyncd.conf.sample \
		${DESTDIR}${PREFIX}/etc/rsyncd.conf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DESTDIR}${DOCSDIR}
.endif

test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>
