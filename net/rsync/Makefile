# ex:ts=8
# Ports collection makefile for:  rsync
# Date created:			  Sat Aug 3, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	rsync
PORTVERSION=	2.5.6
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
CONFIGURE_ARGS=	--disable-debug

.if defined(WITH_POPT_PORT)
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400016
USE_SSH?=	yes
.else
USE_SSH?=	no
.endif

.if ${USE_SSH:U} == YES
CONFIGURE_ARGS+=	--with-rsh=ssh
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
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

post-install:
	@{STRIP_CMD} ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README          ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING         ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${DOCSDIR}
.endif
.if ${USE_SSH:U} == YES
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
