# ex:ts=8
# Ports collection makefile for:  rsync
# Date created:			  Sat Aug 3, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	rsync
PORTVERSION=	2.5.6
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

MAINTAINER=	eik@FreeBSD.org
COMMENT=	A network file distribution/synchronization utility

.if defined(WITH_POPT_PORT)
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
.endif

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_POPT_PORT)
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	NEWS README csprotocol.txt tech_report.tex
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500038
RC_SUBR?=	/etc/rc.subr
.else
USE_RC_SUBR=	yes
.endif

SED_SCRIPT+=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

.if ${OSVERSION} < 400016
WITHOUT_SSH?=	yes
.endif

.if !defined(WITHOUT_SSH)
CONFIGURE_ARGS+=	--with-rsh=ssh
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${OSVERSION} >= 500043
EXTRA_PATCHES=	${FILESDIR}/extra-patch-socket.c
.endif

MAN1=		rsync.1
MAN5=		rsyncd.conf.5

.if !defined(WITH_POPT_PORT)
pre-everything::
	@${ECHO_CMD} "rsync comes with an included version of popt."
	@${ECHO_CMD} "To build rsync with devel/popt instead,"
	@${ECHO_CMD} "hit Ctrl-C now and define WITH_POPT_PORT"
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's:/etc/:${PREFIX}/etc/:g'  \
		${WRKSRC}/rsync.h ${WRKSRC}/rsync.1 ${WRKSRC}/rsyncd.conf.5
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${WRKSRC}/rsync.h ${WRKSRC}/zlib/zutil.h

post-build:
	@${SED} ${SED_SCRIPT} <${FILESDIR}/rsyncd.sh >${WRKDIR}/rsyncd.sh

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/rsync
	@${INSTALL_DATA} ${FILESDIR}/rsyncd.conf.sample ${PREFIX}/etc/
	@[ -f ${PREFIX}/etc/rsyncd.conf ] || cp ${PREFIX}/etc/rsyncd.conf.sample ${PREFIX}/etc/rsyncd.conf
	@${INSTALL_SCRIPT} ${WRKDIR}/rsyncd.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if !defined(WITHOUT_SSH)
	@${CAT} ${PKGMESSAGE}
.endif

test: build
	@cd ${WRKSRC}; ${SH} -c 'umask 0; ./test.sh'

.include <bsd.port.post.mk>
