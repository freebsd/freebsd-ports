# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	2.4.3b2
PORTREVISION?=	0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	amanda
DISTFILES=	amanda-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jeh@FreeBSD.org

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda-client
MASTERPORTNAME=	amanda-server

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
PATCH_STRIP=

.include <bsd.port.pre.mk>
# amanda-server part
.if !defined(CLIENT_ONLY)

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    -DWITH_PLOT to enable ploting, requires X11 libraries"
	@${ECHO} "    -DWITH_SAMBA to enable the use of smbclient"
	@${ECHO} "    -DWITHOUT_GNUTAR to NOT use GNUTar and use the"
	@${ECHO} "        native FreeBSD version"
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_TAPE=tape to specify the default tape device"
	@${ECHO} "        The default is /dev/nrsa0"
	@${ECHO} "    AMANDA_CONFIG=config to specify the default configuation"
	@${ECHO} "        The default is user"
	@${ECHO} ""

RUN_DEPENDS=	${PREFIX}/sbin/amrecover:${PORTSDIR}/misc/amanda-client
BUILD_DEPENDS=	${PREFIX}/sbin/amrecover:${PORTSDIR}/misc/amanda-client

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--with-user=operator --with-group=operator \
		--without-client --disable-libtool --prefix=${PREFIX}

MAN8=		amadmin.8 amcheck.8 amcheckdb.8 amcleanup.8 amdd.8 \
		amdump.8 amflush.8 amgetconf.8 amlabel.8 ammt.8 \
		amoverview.8 amreport.8 amrmtape.8 amstatus.8 \
		amtape.8 amtoc.8 amverify.8

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

.if !defined (WITHOUT_GNUTAR)
CONFIGURE_ARGS+=	--with-gnutar=${PREFIX}/bin/gtar
BUILD_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
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

# amanda-client part
.else

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    -DWITHOUT_GNUTAR to NOT use GNUTar and use the"
	@${ECHO} "        native FreeBSD version"
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_CONFIG=config to specify the default configuation"
	@${ECHO} "        The default is user"
	@${ECHO} ""

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--with-user=operator --with-group=operator \
		--without-server --disable-libtool --prefix=${PREFIX}

MAN8=		amanda.8 amrecover.8 amrestore.8

post-install:
	${MKDIR} ${PREFIX}/share/examples/amanda
	${CP} -R ${WRKSRC}/example/amanda.conf \
		${WRKSRC}/example/chg-multi.conf \
		${WRKSRC}/example/chg-scsi.conf \
		${WRKSRC}/example/disklist \
		${PREFIX}/share/examples/amanda

.if !defined (WITHOUT_GNUTAR)
CONFIGURE_ARGS+=	--with-gnutar=${PREFIX}/bin/gtar
BUILD_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
.endif

.if defined (AMANDA_SERVER)
CONFIGURE_ARGS+=	--with-index-server=${AMANDA_SERVER}
CONFIGURE_ARGS+=	--with-tape-server=${AMANDA_SERVER}
.endif

.if defined (AMANDA_CONFIG)
CONFIGURE_ARGS+=	--with-config=${AMANDA_CONFIG}
.endif

.endif

.include <bsd.port.post.mk>
