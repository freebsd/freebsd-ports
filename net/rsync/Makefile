# ex:ts=8
# Ports collection makefile for:  rsync
# Date created:			  Sat Aug 3, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	rsync
PORTVERSION=	2.5.5
PORTREVISION=	1
PORTCOMMENT=	A network file distribution/synchronization utility
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

MAINTAINER=	obraun@FreeBSD.org

.if defined(WITH_POPT_PORT)
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
.endif

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
.if defined(WITH_POPT_PORT)
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS=	--with-included-popt
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400016
USE_SSH?=	yes
.else
USE_SSH?=	no
.endif

.if ${USE_SSH:U} == YES
EXTRA_PATCHES=	${FILESDIR}/ssh-patch-*
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--disable-debug --enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-debug --disable-ipv6
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
.if defined(WITH_SSH)
	@${REINPLACE_CMD} -e 's/"rsh"/"ssh"/g' ${WRKSRC}/rsync.h
.endif

post-install:
	@strip ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
