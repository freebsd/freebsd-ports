# Created by: gpalmer
# $FreeBSD$

PORTNAME=	amanda
PORTVERSION=	2.6.1p2
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	SF/amanda/amanda%20-%20stable/${PORTVERSION}
PKGNAMESUFFIX?=	26-server

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT?=	The Advanced Maryland Automatic Network Disk Archiver (server)

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda26-client

USES=		gmake perl5 pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_OPENSSL=	yes
PATCH_STRIP=
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--without-amlibexecdir \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--prefix=${PREFIX} \
		--disable-glibtest \
		--with-user=${AMANDA_USER} --with-group=${AMANDA_GROUP} \
		--with-bsdtcp-security --with-bsdudp-security \
		--with-ssh-security

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNUTAR
GNUTAR_DESC=	use GNU tar

AMANDA_USER?=		operator
AMANDA_GROUP?=		operator
AMANDA_GNUTAR_LISTDIR?=	${PREFIX}/var/amanda/gnutar-lists
AMANDA_DATES?=		${PREFIX}/var/amanda/amandates
PLIST_SUB=		SHLIBVER=${PORTVERSION} AMANDA_DATES=${AMANDA_DATES}

# amanda-server/amanda-client common part
.if defined (AMANDA_SERVER)
CONFIGURE_ARGS+=	--with-index-server=${AMANDA_SERVER}
CONFIGURE_ARGS+=	--with-tape-server=${AMANDA_SERVER}
.endif

.if defined (AMANDA_CONFIG)
CONFIGURE_ARGS+=	--with-config=${AMANDA_CONFIG}
.endif

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	PLOT SAMBA MTX AESPIPE S3
PLOT_DESC=	Enable ploting, requires X11 libraries
SAMBA_DESC=	Enable the use of smbclient
MTX_DESC=	Enable the use of mtx changer scripts
AESPIPE_DESC=	Enable encryption. Needed by amcrypt
S3_DESC=	Enable Amazon S3 device support
.else
OPTIONS_DEFINE+=	ZFSCOMP
ZFSCOMP_DESC=	Accurate estimation of compressed ZFS filesystems
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTAR}
CONFIGURE_ARGS+=--with-gnutar-listdir=${AMANDA_GNUTAR_LISTDIR} \
		--with-gnutar=${LOCALBASE}/bin/gtar
BUILD_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
.endif

# amanda-server part
.if !defined(CLIENT_ONLY)

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_TAPE=tape to specify the default tape device"
	@${ECHO} "        The default is /dev/nrsa0"
	@${ECHO} "    AMANDA_CONFIG=config to specify the default configuration"
	@${ECHO} "        The default is DailySet1"
	@${ECHO} "    AMANDA_USER=user to specify the default user"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_GROUP=group to specify the default group"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_DATES=path to client amandates file"
	@${ECHO} ""

CONFLICTS=	amanda-server-2.5.* amanda-server-3.* amanda25-server-*

BUILD_DEPENDS+=	${LOCALBASE}/lib/amanda/libamandad-${PORTVERSION}.so:${PORTSDIR}/misc/amanda26-client
RUN_DEPENDS+=	${LOCALBASE}/lib/amanda/libamandad-${PORTVERSION}.so:${PORTSDIR}/misc/amanda26-client

CONFIGURE_ARGS+=--without-client

MAN5=		disklist.5 \
		tapelist.5
MAN7=		amanda-changers.7 \
		amanda-devices.7
MAN8=		amaddclient.8 amadmin.8 amaespipe.8 amcheck.8 \
		amcheckdb.8 amcheckdump.8 amcleanup.8 \
		amcrypt.8 amcryptsimple.8 amcrypt-ossl-asym.8 amcrypt-ossl.8 \
		amdevcheck.8 \
		amdump.8 amfetchdump.8 amflush.8 amgetconf.8 amgpgcrypt.8 \
		amlabel.8 \
		amoverview.8 amreport.8 amrestore.8 amrmtape.8 \
		amserverconfig.8 amservice.8 amstatus.8 \
		amtape.8 amtoc.8 amtapetype.8 \
		amvault.8

.if ${PORT_OPTIONS:MPLOT}
BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
MAN8+=		amplot.8
PLIST_SUB+=	PLOT=''
CONFIGURE_ARGS+=	--with-gnuplot=${LOCALBASE}/bin/gnuplot
.else
PLIST_SUB+=	PLOT='@comment '
CONFIGURE_ARGS+=	--without-gnuplot
.endif

.if ${PORT_OPTIONS:MSAMBA}
SAMBA_PORT?=	samba36
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/net/${SAMBA_PORT}
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/${SAMBA_PORT}
CONFIGURE_ARGS+=	--with-smbclient=${LOCALBASE}/bin/smbclient
.endif

.if ${PORT_OPTIONS:MMTX}
BUILD_DEPENDS+=	mtx:${PORTSDIR}/misc/mtx
RUN_DEPENDS+=	mtx:${PORTSDIR}/misc/mtx
.endif

.if ${PORT_OPTIONS:MAESPIPE}
RUN_DEPENDS+=	aespipe:${PORTSDIR}/security/aespipe
.else
.endif

# If configure founds libcurl, automatically enabled it (with plist change).
.if ${PORT_OPTIONS:MS3}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-s3-device
PLIST_SUB+=	S3DEVICE=''
.else
CONFIGURE_ARGS+=	--disable-s3-device
PLIST_SUB+=	S3DEVICE='@comment '
.endif

.if defined (AMANDA_TAPE)
CONFIGURE_ARGS+=	--with-tape-device=${AMANDA_TAPE}
.endif

# amanda-client part
.else

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_CONFIG=config to specify the default configuation"
	@${ECHO} "        The default is DailySet1"
	@${ECHO} "    AMANDA_GNUTAR_LISTDIR=dir to specify the directory that"
	@${ECHO} "        the gnutar index files should live in"
	@${ECHO} "        The default is ${PREFIX}/var/amanda/gnutar-lists"
	@${ECHO} "    AMANDA_USER=user to specify the default user"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_GROUP=group to specify the default group"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_DATES=path to client amandates file"
	@${ECHO} ""

CONFLICTS=	amanda-client-2.5.* amanda-client-3.* amanda25-client-*
CONFIGURE_ARGS+=--without-server --with-amandates=${AMANDA_DATES}

MAN5=		amanda-archive-format.5 \
		amanda-client.conf.5 \
		amanda.conf.5
MAN7=		amanda-applications.7 \
		amanda-auth.7 \
		amanda-scripts.7
MAN8=		amanda.8 \
		amarchiver.8 \
		amgtar.8 \
		amrecover.8 \
		amsamba.8 \
		amstar.8 \
		amzfs-sendrecv.8 \
		amzfs-snapshot.8 \
		script-email.8

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/chg-multi.conf \
		${WRKSRC}/example/chg-scsi.conf \
		${WRKSRC}/example/disklist \
		${EXAMPLESDIR}
.endif
	${MKDIR} ${AMANDA_GNUTAR_LISTDIR}
	${CHOWN} ${AMANDA_USER}:${AMANDA_GROUP} ${AMANDA_GNUTAR_LISTDIR}
	${TOUCH} ${AMANDA_DATES}
	${CHOWN} ${AMANDA_USER}:${AMANDA_GROUP} ${AMANDA_DATES}

.endif

.if ${PORT_OPTIONS:MZFSCOMP}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-application-src::amzfs-sendrecv.pl
.endif

# MEMO:
#   Prefix @WANT_SERVER_TRUE@ for server only files.
#   Prefix @WANT_CLIENT_TRUE@ for client only files.
#   For debugging: dbprintf(_("getcmd: %s\n"), line);
# Maintainer TODO:
#   o amanda-server installs libexec/amanda/amandad, sbin/amarchiver
#     which should be handled by amanda-client only.
#   o pthread issue: http://wiki.zmanda.com/index.php/Installation/OS_Specific_Notes/Installing_Amanda_on_FreeBSD#Threading_and_-pthread

.include <bsd.port.mk>
