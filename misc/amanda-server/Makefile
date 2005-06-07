# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	2.4.5
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	amanda
DISTFILES=	amanda-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	The Advanced Maryland Automatic Network Disk Archiver (server)

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda-client
MASTERPORTNAME=	amanda-server

NO_LATEST_LINK=	yes
USE_AUTOCONF_VER=	259
USE_GMAKE=	yes
PATCH_STRIP=

.include <bsd.port.pre.mk>

.if exists(/usr/include/sys/scsiio.h)
.error You have the file /usr/include/sys/scsiio.h on your system.  This was removed after FreeBSD 3.5 and will break the build of this port.  Please remove it.
.endif

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

AMANDA_USER?=		operator
AMANDA_GROUP?=		operator
AMANDA_GNUTAR_LISTDIR?=	${PREFIX}/var/amanda/gnutar-lists

# amanda-server part
.if !defined(CLIENT_ONLY)

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    -DWITH_PLOT to enable ploting, requires X11 libraries"
	@${ECHO} "    -DWITH_SAMBA to enable the use of smbclient"
	@${ECHO} "    -DWITH_MTX to enable the use of mtx changer scripts"
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
	@${ECHO} "    AMANDA_PORTRANGE=low,high to restrict Amanda to TCP ports"
	@${ECHO} "        between low and high when connecting from the server"
	@${ECHO} "        to the client for data, messages, and indexing."
	@${ECHO} "        The default is no restriction on TCP ports."
	@${ECHO} "    AMANDA_UDPPORTRANGE=low,high to restrict Amanda to UDP ports"
	@${ECHO} "        between low and high when connecting from the client"
	@${ECHO} "        to the server. Use ports below 1024."
	@${ECHO} "        The default is no restriction on UDP ports."
	@${ECHO} ""

USE_PERL5=	yes

RUN_DEPENDS=	${LOCALBASE}/sbin/amrecover:${PORTSDIR}/misc/amanda-client
BUILD_DEPENDS=	${LOCALBASE}/sbin/amrecover:${PORTSDIR}/misc/amanda-client

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--without-client --disable-libtool --prefix=${PREFIX} \
		--with-user=${AMANDA_USER} --with-group=${AMANDA_GROUP} \
		--with-gnutar-listdir=${AMANDA_GNUTAR_LISTDIR}

MAN8=		amadmin.8 amcheck.8 amcheckdb.8 amcleanup.8 amdd.8 \
		amdump.8 amflush.8 amgetconf.8 amlabel.8 ammt.8 \
		amoverview.8 amreport.8 amrmtape.8 amstatus.8 \
		amtape.8 amtoc.8 amverify.8 amverifyrun.8 amtapetype.8

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

.if defined (WITH_MTX)
BUILD_DEPENDS+=	mtx:${PORTSDIR}/misc/mtx
RUN_DEPENDS+=	mtx:${PORTSDIR}/misc/mtx
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

.if defined (AMANDA_UDPPORTRANGE)
CONFIGURE_ARGS+=	--with-udpportrange=${AMANDA_UDPPORTRANGE}
.endif

.if defined (AMANDA_PORTRANGE)
CONFIGURE_ARGS+=	--with-portrange=${AMANDA_PORTRANGE}
.endif

#
# Before 4.0, pre-CAM scsiio.h existed
.if ${OSVERSION} < 400000
PLIST_SUB+=	SCSICHG=''
.elif ${OSVERSION} >= 480000
.if ${MACHINE_ARCH} == "amd64"
PLIST_SUB+=	SCSICHG='@comment '
.elif ${OSVERSION} >= 502000
PLIST_SUB+=	SCSICHG='@comment '
.else
PLIST_SUB+=	SCSICHG=''
.endif
.else
PLIST_SUB+=	SCSICHG='@comment '
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
	@${ECHO} "    AMANDA_PORTRANGE=low,high to restrict Amanda to TCP ports"
	@${ECHO} "        between low and high when connecting from the server"
	@${ECHO} "        to the client for data, messages, and indexing."
	@${ECHO} "        The default is no restriction on TCP ports."
	@${ECHO} "    AMANDA_UDPPORTRANGE=low,high to restrict Amanda to UDP ports"
	@${ECHO} "        between low and high when connecting from the client"
	@${ECHO} "        to the server. Use ports below 1024."
	@${ECHO} "        The default is no restriction on UDP ports."
	@${ECHO} ""

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--without-server --disable-libtool --prefix=${PREFIX} \
		--with-user=${AMANDA_USER} --with-group=${AMANDA_GROUP} \
		--with-gnutar-listdir=${AMANDA_GNUTAR_LISTDIR}

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

.if defined (AMANDA_PORTRANGE)
CONFIGURE_ARGS+=	--with-portrange=${AMANDA_PORTRANGE}
.endif

.endif

.include <bsd.port.post.mk>
