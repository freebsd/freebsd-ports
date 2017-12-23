# Created by: gpalmer
# $FreeBSD$

PORTNAME=	amanda
PORTVERSION=	3.3.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	SF/amanda/amanda%20-%20stable/${PORTVERSION}
PKGNAMESUFFIX?=	-server

MAINTAINER=	fbsd@dylanleigh.net
COMMENT?=	Advanced Maryland Automatic Network Disk Archiver (server)

RUN_DEPENDS=	perl-amanda:misc/amanda-perl-wrapper
BUILD_DEPENDS=	perl-amanda:misc/amanda-perl-wrapper

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda-client

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		charsetfix gmake libtool perl5 pkgconfig ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--without-amlibexecdir \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump \
		--prefix=${PREFIX} \
		--disable-glibtest \
		--with-user=${USERS} --with-group=${AMANDA_GROUP} \
		--with-bsdtcp-security --with-bsdudp-security \
		--with-ssh-security \
		--disable-installperms --with-security-file=${ETCDIR}/security.conf
CONFIGURE_ENV=	PERL=${LOCALBASE}/bin/perl-amanda
PKG_MESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GNUTAR
OPTIONS_DEFAULT=	GNUTAR
GNUTAR_DESC=	use GNU tar

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
PLIST_SUB=		SHLIBVER=${PORTVERSION} AMANDA_GROUP=${AMANDA_GROUP}

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTAR}
CONFIGURE_ARGS+=--with-gnutar-listdir=${AMANDA_GNUTAR_LISTDIR} \
		--with-gnutar=${LOCALBASE}/bin/gtar
BUILD_DEPENDS+=	gtar:archivers/gtar
RUN_DEPENDS+=	gtar:archivers/gtar
.endif

# amanda-server part
.if !defined(CLIENT_ONLY)

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PLIST_SUB+=	CLIENT_ONLY="@comment " SERVER_ONLY=""
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

CONFLICTS=	amanda-server-2.* amanda-server-3.2.* amanda2[56]-server-*

BUILD_DEPENDS+=	${LOCALBASE}/lib/amanda/libamandad-${PORTVERSION}.so:misc/amanda-client
RUN_DEPENDS+=	${LOCALBASE}/lib/amanda/libamandad-${PORTVERSION}.so:misc/amanda-client \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

CONFIGURE_ARGS+=--without-client

.if ${PORT_OPTIONS:MPLOT}
BUILD_DEPENDS+=	gnuplot:math/gnuplot
RUN_DEPENDS+=	gnuplot:math/gnuplot
PLIST_SUB+=	PLOT=''
CONFIGURE_ARGS+=	--with-gnuplot=${LOCALBASE}/bin/gnuplot
.else
PLIST_SUB+=	PLOT='@comment '
CONFIGURE_ARGS+=	--without-gnuplot
.endif

.if ${PORT_OPTIONS:MSAMBA}
USES+=		pkgconfig samba
CONFIGURE_ARGS+=	--with-smbclient=${LOCALBASE}/bin/smbclient
.endif

# If configure founds libcurl, automatically enabled it (with plist change).
.if ${PORT_OPTIONS:MS3}
LIB_DEPENDS+=	libcurl.so:ftp/curl
CONFIGURE_ARGS+=	--enable-s3-device
PLIST_SUB+=	S3DEVICE=''
.else
CONFIGURE_ARGS+=	--disable-s3-device
PLIST_SUB+=	S3DEVICE='@comment '
.endif

# amanda-client part
.else

PKGINSTALL=	${WRKDIR}/pkg-install.client
PKGDEINSTALL=	${PKGINSTALL}
PLIST_SUB+=	CLIENT_ONLY="" SERVER_ONLY="@comment "
SUB_FILES+=	pkg-install.client
SUB_LIST+=	AMANDA_DATES=${AMANDA_DATES} AMANDA_GNUTAR_LISTDIR=${AMANDA_GNUTAR_LISTDIR} \
		USERS=${USERS} AMANDA_GROUP=${AMANDA_GROUP}

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

CONFLICTS=	amanda-client-2.* amanda-client-3.2.* amanda2[56]-client-*
CONFIGURE_ARGS+=--without-server --with-amandates=${AMANDA_DATES}
.if defined(AMANDA_NO_SNAPSHOT_DUMP)
CFLAGS=		-DFreeBSD_NO_SNAPSHOT_DUMP=t
.endif

.endif

# See PR 194811.
post-patch:
	${REINPLACE_CMD} -e 's|#undef bool||g' ${WRKSRC}/perl/Amanda/*.c

# MEMO:
#   Prefix @WANT_SERVER_TRUE@ for server only files.
#   Prefix @WANT_CLIENT_TRUE@ for client only files.
#   For debugging: dbprintf(_("getcmd: %s\n"), line);

.include <bsd.port.mk>
