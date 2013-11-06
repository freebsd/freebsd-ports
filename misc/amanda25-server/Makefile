# Created by: gpalmer
# $FreeBSD$

PORTNAME=	amanda
PORTVERSION=	2.5.1p3
PORTREVISION?=	7
PKGNAMESUFFIX?=	25-server
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	SF/amanda/amanda%20-%20stable/${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT?=	The Advanced Maryland Automatic Network Disk Archiver (server)

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda25-client

USE_AUTOTOOLS=	autoconf
USES=		gmake
USE_OPENSSL=	yes
PATCH_STRIP=
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--disable-libtool --prefix=${PREFIX} \
		--with-user=${AMANDA_USER} --with-group=${AMANDA_GROUP}
USE_LDCONFIG=	yes

SAMBA_PORT?=	net/samba36

OPTIONS_DEFINE=	GNUTAR SSH
OPTIONS_DEFAULT=	SSH
GNUTAR_DESC=	use GNU tar
SSH_DESC=	Enable ssh-auth

AMANDA_USER?=		operator
AMANDA_GROUP?=		operator
AMANDA_GNUTAR_LISTDIR?=	${PREFIX}/var/amanda/gnutar-lists
PLIST_SUB=		SHLIBVER=${PORTVERSION}

# amanda-server/amanda-client common part
.if defined (AMANDA_SERVER)
CONFIGURE_ARGS+=	--with-index-server=${AMANDA_SERVER}
CONFIGURE_ARGS+=	--with-tape-server=${AMANDA_SERVER}
.endif

.if defined (AMANDA_CONFIG)
CONFIGURE_ARGS+=	--with-config=${AMANDA_CONFIG}
.endif

.if defined (AMANDA_UDPPORTRANGE)
CONFIGURE_ARGS+=	--with-udpportrange=${AMANDA_UDPPORTRANGE}
.endif

# AMANDA_PORTRANGE is obsoleted.  Use AMANDA_TCPPORTRANGE instead.
.if defined (AMANDA_PORTRANGE)
AMANDA_TCPPORTRANGE=	${AMANDA_PORTRANGE}
.endif
.if defined (AMANDA_TCPPORTRANGE)
CONFIGURE_ARGS+=	--with-tcpportrange=${AMANDA_TCPPORTRANGE}
.endif

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	PLOT SAMBA MTX AESPIPE
PLOT_DESC=	Eenable ploting, requires X11 libraries
SAMBA_DESC=	Enable the use of smbclient
MTX_DESC=	Enable the use of mtx changer scripts
AESPIPE_DESC=	Enable encryption. Needed by amcrypt
.else
OPTIONS_DEFINE+=	DUMP_SNAPSHOT
DUMP_SNAPSHOT_DESC=	Use snapshot by using dump -L
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSH}
CONFIGURE_ARGS+=	--with-ssh-security
.endif

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
	@${ECHO} "        The default is user"
	@${ECHO} "    AMANDA_USER=user to specify the default user"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_GROUP=group to specify the default group"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_TCPPORTRANGE=low,high to restrict Amanda to TCP ports"
	@${ECHO} "        between low and high when connecting from the server"
	@${ECHO} "        to the client for data, messages, and indexing."
	@${ECHO} "        The default is no restriction on TCP ports."
	@${ECHO} "    AMANDA_UDPPORTRANGE=low,high to restrict Amanda to UDP ports"
	@${ECHO} "        between low and high when connecting from the client"
	@${ECHO} "        to the server. Use ports below 1024."
	@${ECHO} "        The default is no restriction on UDP ports."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^OPENSSL=.*$$|OPENSSL=${OPENSSLBASE}/bin/openssl|' \
		${WRKSRC}/server-src/amcrypt-ossl.sh.in \
		${WRKSRC}/server-src/amcrypt-ossl-asym.sh.in

USES+=		perl5

BUILD_DEPENDS+=	${LOCALBASE}/sbin/amrecover:${PORTSDIR}/misc/amanda25-client
RUN_DEPENDS+=	${LOCALBASE}/sbin/amrecover:${PORTSDIR}/misc/amanda25-client

CONFLICTS=	amanda-server-2.6.* amanda-server-3.* amanda26-server-*
CONFIGURE_ARGS+=--without-client

MAN8=		amadmin.8 amaespipe.8 amcheck.8 \
		amcheckdb.8 amcleanup.8 \
		amcrypt.8 amcrypt-ossl-asym.8 amcrypt-ossl.8 amdd.8 \
		amdump.8 amfetchdump.8 amflush.8 amgetconf.8 amlabel.8 ammt.8 \
		amoverview.8 amreport.8 amrmtape.8 amstatus.8 \
		amtape.8 amtoc.8 amverify.8 amverifyrun.8 amtapetype.8

.if ${PORT_OPTIONS:MPLOT}
BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
MAN8+=		amplot.8
PLIST_SUB+=	PLOT=''
.else
PLIST_SUB+=	PLOT='@comment '
.endif

.if ${PORT_OPTIONS:MSAMBA}
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/${SAMBA_PORT}
RUN_DEPENDS+=	smbclient:${PORTSDIR}/${SAMBA_PORT}
CONFIGURE_ARGS+=	--with-smbclient=${LOCALBASE}/bin/smbclient
.endif

.if ${PORT_OPTIONS:MMTX}
BUILD_DEPENDS+=	mtx:${PORTSDIR}/misc/mtx
RUN_DEPENDS+=	mtx:${PORTSDIR}/misc/mtx
.endif

.if ${PORT_OPTIONS:MAESPIPE}
RUN_DEPENDS+=	aespipe:${PORTSDIR}/security/aespipe
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
	@${ECHO} "        The default is user"
	@${ECHO} "    AMANDA_GNUTAR_LISTDIR=dir to specify the directory that"
	@${ECHO} "        the gnutar index files should live in"
	@${ECHO} "        The default is /var/amanda/gnutar-lists"
	@${ECHO} "    AMANDA_USER=user to specify the default user"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_GROUP=group to specify the default group"
	@${ECHO} "        The default is operator"
	@${ECHO} "    AMANDA_TCPPORTRANGE=low,high to restrict Amanda to TCP ports"
	@${ECHO} "        between low and high when connecting from the server"
	@${ECHO} "        to the client for data, messages, and indexing."
	@${ECHO} "        The default is no restriction on TCP ports."
	@${ECHO} "    AMANDA_UDPPORTRANGE=low,high to restrict Amanda to UDP ports"
	@${ECHO} "        between low and high when connecting from the client"
	@${ECHO} "        to the server. Use ports below 1024."
	@${ECHO} "        The default is no restriction on UDP ports."
	@${ECHO} ""

CONFLICTS=	amanda-client-2.6.* amanda-client-3.* amanda26-client-*
CONFIGURE_ARGS+=--without-server

MAN5=		amanda.conf.5 amanda-client.conf.5
MAN8=		amanda.8 amrecover.8 amrestore.8

post-install:
	${MKDIR} ${PREFIX}/share/examples/amanda
	${CP} -R ${WRKSRC}/example/amanda.conf \
		${WRKSRC}/example/chg-multi.conf \
		${WRKSRC}/example/chg-scsi.conf \
		${WRKSRC}/example/disklist \
		${PREFIX}/share/examples/amanda
	${MKDIR} ${AMANDA_GNUTAR_LISTDIR}
	${CHOWN} ${AMANDA_USER}:${AMANDA_GROUP} ${AMANDA_GNUTAR_LISTDIR}
	${TOUCH} /etc/amandates
	${CHOWN} ${AMANDA_USER}:${AMANDA_GROUP} /etc/amandates

.if ${PORT_OPTIONS:MDUMP_SNAPSHOT}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-sendbackup-dump.c
.endif

.endif

# Maintainer TODO:
#   o amanda-server installs lib/libamandad.a which should be handled by
#     amanda-client only.

.include <bsd.port.mk>
