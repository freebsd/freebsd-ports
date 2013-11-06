# Created by: gpalmer
# $FreeBSD$

PORTNAME=	amanda
PORTVERSION=	3.2.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	SF/amanda/amanda%20-%20stable/${PORTVERSION}
PKGNAMESUFFIX?=	32-server

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT?=	The Advanced Maryland Automatic Network Disk Archiver (server)

RUN_DEPENDS=	perl-amanda:${PORTSDIR}/misc/amanda-perl-wrapper
BUILD_DEPENDS=	perl-amanda:${PORTSDIR}/misc/amanda-perl-wrapper

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda32-client

GNU_CONFIGURE=	yes
USES=		gmake perl5 pkgconfig
USE_GNOME=	glib20
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--without-amlibexecdir \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump \
		--prefix=${PREFIX} \
		--disable-glibtest \
		--with-user=${USERS} --with-group=${AMANDA_GROUP} \
		--with-bsdtcp-security --with-bsdudp-security \
		--with-ssh-security
CONFIGURE_ENV=	PERL=${LOCALBASE}/bin/perl-amanda
PKG_MESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

OPTIONS_DEFINE=	GNUTAR
OPTIONS_DEFAULT=	GNUTAR
GNUTAR_DESC=	Use GNU tar

.if defined(AMANDA_USER)
USERS=		${AMANDA_USER}
.else
USERS?=		amanda
.endif
.if !defined(AMANDA_GROUP)
AMANDA_GROUP=	amanda
.endif
GROUPS?=	operator amanda

AMANDA_GNUTAR_LISTDIR?=	${PREFIX}/var/amanda/gnutar-lists
AMANDA_DATES?=		${PREFIX}/var/amanda/amandates
PLIST_SUB=		SHLIBVER=${PORTVERSION} AMANDA_DATES=${AMANDA_DATES}

# amanda-server/amanda-client common part
.if defined (AMANDA_SERVER)
CONFIGURE_ARGS+=	--with-index-server=${AMANDA_SERVER}
CONFIGURE_ARGS+=	--with-tape-server=${AMANDA_SERVER}
.endif

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	PLOT SAMBA S3
PLOT_DESC=	Enable ploting, requires X11 libraries
SAMBA_DESC=	Enable the use of smbclient
S3_DESC=	Enable Amazon S3 device support
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTAR}
CONFIGURE_ARGS+=--with-gnutar-listdir=${AMANDA_GNUTAR_LISTDIR} \
		--with-gnutar=${LOCALBASE}/bin/gtar
BUILD_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
.endif

# amanda-server part
.if !defined(CLIENT_ONLY)

SUB_FILES+=	pkg-install pkg-deinstall
SUB_LIST+=	PERL=${PERL} SITE_PERL_REL=${SITE_PERL_REL}

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_USER=user to specify the default user"
	@${ECHO} "        The default is amanda"
	@${ECHO} "    AMANDA_GROUP=group to specify the default group"
	@${ECHO} "        The default is amanda"
	@${ECHO} "    AMANDA_DATES=path to client amandates file"
	@${ECHO} ""

CONFLICTS=	amanda-server-2.* amanda-server-3.3.* amanda2[56]-server-*

BUILD_DEPENDS+=	${LOCALBASE}/lib/amanda/libamandad-${PORTVERSION}.so:${PORTSDIR}/misc/amanda32-client
RUN_DEPENDS+=	${LOCALBASE}/lib/amanda/libamandad-${PORTVERSION}.so:${PORTSDIR}/misc/amanda32-client

CONFIGURE_ARGS+=--without-client

MAN5=		disklist.5 \
		tapelist.5
MAN7=		amanda-changers.7 \
		amanda-compatibility.7 \
		amanda-devices.7 \
		amanda-taperscan.7
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

# If configure founds libcurl, automatically enabled it (with plist change).
.if ${PORT_OPTIONS:MS3}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-s3-device
PLIST_SUB+=	S3DEVICE=''
.else
CONFIGURE_ARGS+=	--disable-s3-device
PLIST_SUB+=	S3DEVICE='@comment '
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

# amanda-client part
.else

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    AMANDA_SERVER=server to specify a server name"
	@${ECHO} "        The default is `uname -n`"
	@${ECHO} "    AMANDA_GNUTAR_LISTDIR=dir to specify the directory that"
	@${ECHO} "        the gnutar index files should live in"
	@${ECHO} "        The default is ${PREFIX}/var/amanda/gnutar-lists"
	@${ECHO} "    AMANDA_USER=user to specify the default user"
	@${ECHO} "        The default is amanda"
	@${ECHO} "    AMANDA_GROUP=group to specify the default group"
	@${ECHO} "        The default is amanda"
	@${ECHO} "    AMANDA_DATES=path to client amandates file"
	@${ECHO} ""

CONFLICTS=	amanda-client-2.* amanda-client-3.3.* amanda2[56]-client-*
CONFIGURE_ARGS+=--without-server --with-amandates=${AMANDA_DATES}
.if defined(AMANDA_NO_SNAPSHOT_DUMP)
CFLAGS=		-DFreeBSD_NO_SNAPSHOT_DUMP=t
.endif

MAN5=		amanda-archive-format.5 \
		amanda-client.conf.5 \
		amanda.conf.5
MAN7=		amanda-applications.7 \
		amanda-auth.7 \
		amanda-match.7 \
		amanda-scripts.7
MAN8=		amanda.8 \
		amarchiver.8 \
		amgtar.8 \
		ampgsql.8 \
		amraw.8 \
		amrecover.8 \
		amsamba.8 \
		amstar.8 \
		amsuntar.8 \
		amzfs-sendrecv.8 \
		amzfs-snapshot.8 \
		script-email.8

post-install:
	${MKDIR} ${AMANDA_GNUTAR_LISTDIR}
	${CHOWN} ${USERS}:${AMANDA_GROUP} ${AMANDA_GNUTAR_LISTDIR}
	${TOUCH} ${AMANDA_DATES}
	${CHOWN} ${USERS}:${AMANDA_GROUP} ${AMANDA_DATES}
	${CAT} ${PKGMESSAGE}

.endif

# MEMO:
#   Prefix @WANT_SERVER_TRUE@ for server only files.
#   Prefix @WANT_CLIENT_TRUE@ for client only files.
#   For debugging: dbprintf(_("getcmd: %s\n"), line);

.include <bsd.port.mk>
