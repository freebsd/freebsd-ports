# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	2.4.2p1
PORTREVISION?=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	amanda
DISTFILES=	amanda-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jeh@FreeBSD.org

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda24-client
MASTERPORTNAME=	amanda24-server

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PATCH_STRIP=

.include <bsd.port.pre.mk>
# amanda24-server part
.if !defined(CLIENT_ONLY)

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    -DWITH_PLOT to enable ploting, requires X11 libraries"
	@${ECHO} "    -DWITH_SAMBA to enable the use of smbclient"
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_TAPE=tape to specify the default tape device"
	@${ECHO} "        The default is /dev/nrsa0"
	@${ECHO} "    AMANDA_CONFIG=config to specify the default configuation"
	@${ECHO} "        The default is user"
	@${ECHO} ""

RUN_DEPENDS=	${LOCALBASE}/sbin/amrecover:${PORTSDIR}/misc/amanda24-client \
		gtar:${PORTSDIR}/archivers/gtar
BUILD_DEPENDS=	${LOCALBASE}/sbin/amrecover:${PORTSDIR}/misc/amanda24-client \
		gtar:${PORTSDIR}/archivers/gtar

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--with-user=operator --with-group=operator \
		--without-client --with-gnutar=${PREFIX}/bin/gtar

MAN8=		amadmin.8 amcheck.8 amcheckdb.8 amcleanup.8 amdump.8 \
		amflush.8 amgetconf.8 amlabel.8 amoverview.8 amreport.8 \
		amrmtape.8 amstatus.8 amtape.8 amtoc.8 amverify.8

.if defined (WITH_PLOT)
BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
MAN8+=		amplot.8
PLIST_SUB+=	PLOT=''
.else
PLIST_SUB+=	PLOT='@comment '
.endif

.if defined (WITH_SAMBA)
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/net/samba
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba
CONFIGURE_ARGS+=	--with-smbclient=${PREFIX}/bin/smbclient
.endif

.if defined (AMANDA_SERVER)
CONFIGURE_ARGS+=	--with-index-server=${AMANDA_SERVER}
CONFIGURE_ARGS+=	--with-tape-server=${AMANDA_SERVER}
.endif

.if defined (AMANDA_TAPE)
CONFIGURE_ARGS+=	--with-tape-device=${AMANDA_TAPE}
.endif

.if defined (AMANDA_CONFIG)
CONFIGURE_ARGS+=	--with-config=${AMANDA_CONFIG}
.endif

#
# Before 4.0, pre-CAM scsiio.h existed
.if ${OSVERSION} < 400000
PLIST_SUB+=	SCSICHG=''
.else
PLIST_SUB+=	SCSICHG='@comment '
.endif

# amanda24-client part
.else

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_CONFIG=config to specify the default configuation"
	@${ECHO} "        The default is user"
	@${ECHO} ""

BUILD_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--with-user=operator --with-group=operator \
		--without-server --with-gnutar=${PREFIX}/bin/gtar

MAN8=		amanda.8 amrecover.8 amrestore.8

post-install:
	${MKDIR} ${PREFIX}/share/examples/amanda
	${CP} -R ${WRKSRC}/example/amanda.conf \
		${WRKSRC}/example/chg-multi.conf \
		${WRKSRC}/example/chg-scsi.conf \
		${WRKSRC}/example/disklist \
		${PREFIX}/share/examples/amanda

.if defined (AMANDA_SERVER)
CONFIGURE_ARGS+=	--with-index-server=${AMANDA_SERVER}
CONFIGURE_ARGS+=	--with-tape-server=${AMANDA_SERVER}
.endif

.if defined (AMANDA_CONFIG)
CONFIGURE_ARGS+=	--with-config=${AMANDA_CONFIG}
.endif

.endif

.include <bsd.port.post.mk>
