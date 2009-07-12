# New ports collection makefile for:	samba4
# Date created:				28 Jun 2006
# Whom:					timur@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=		${SAMBA_PORTNAME}
PORTVERSION?=		${SAMBA_VERSION}
CATEGORIES?=		net
MASTER_SITES=		${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	samba4
PKGNAMESUFFIX?=		-devel
DISTNAME=		${SAMBA_DISTNAME}

MAINTAINER?=		timur@FreeBSD.org
COMMENT?=		A free SMB and CIFS client and server for UNIX

CONFLICTS?=

SAMBA_PORTNAME=		samba4
SAMBA_VERSION=		4.0.0.a8
SAMBA_DISTNAME=		${SAMBA_PORTNAME:S|4$||}-${SAMBA_VERSION:S|.p|pre|:S|.r|rc|:S|.t|tp|:S|.a|alpha|}

LATEST_LINK?=		${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=		${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
#PATCHDIR=		${.CURDIR}/../samba34/files
#MD5_FILE=		${.CURDIR}/../samba34/distinfo
PATCH_WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC?=		${WRKDIR}/${DISTNAME}/source4
IPATHS=			-I${WRKDIR}/${DISTNAME}/lib/replace
AUTOHEADER_ARGS=	${IPATHS}
AUTOCONF_ARGS=		${IPATHS}

.if !defined(SAMBA_SUBPORT)

CONFLICTS?=		ja-samba-[23].* samba-[2-9].* sharity-light-1.*

IPATHS+=		-I${WRKDIR}/${DISTNAME}/source4

USE_PERL5=		yes
USE_PYTHON=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		pkgconfig
USE_AUTOTOOLS=		autoconf:262 autoheader:262
# directories
VARDIR=			/var
SAMBA_LOGDIR=		${VARDIR}/log/${PORTNAME}
SAMBA_RUNDIR=		${VARDIR}/run/${PORTNAME}
SAMBA_LOCKDIR=		${VARDIR}/db/${PORTNAME}
SAMBA_PRIVATEDIR?=	${SAMBA_LOCKDIR}/private
SAMBA_CONFDIR?=		${PREFIX}/etc
SAMBA_LIBDIR=		${PREFIX}/lib/${PORTNAME}
SAMBA_INCLUDEDIR=	${PREFIX}/include/${PORTNAME}
RC_DIR=			${PREFIX}/etc/rc.d
SAMBA_CONFIG=		smb.conf

CONFIGURE_ARGS+=	--exec-prefix="${PREFIX}" \
			--sysconfdir="${SAMBA_CONFDIR}" \
			--includedir="${SAMBA_INCLUDEDIR}" \
			--datadir="${DATADIR}" \
			--libdir="${SAMBA_LIBDIR}" \
			--with-modulesdir="${SAMBA_LIBDIR}/modules" \
			--localstatedir="${VARDIR}" \
			--with-piddir="${SAMBA_RUNDIR}" \
			--with-winbindd-socket-dir="${SAMBA_RUNDIR}/winbindd" \
			--with-winbindd-privileged-socket-dir="${SAMBA_RUNDIR}/winbindd_privileged" \
			--with-ntp-signd-socket-dir="${SAMBA_RUNDIR}/ntp_signd" \
			--with-lockdir="${SAMBA_LOCKDIR}" \
			--with-privatedir="${SAMBA_PRIVATEDIR}" \
			--with-logfilebase="${SAMBA_LOGDIR}"

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

OPTIONS=	\
		DEBUG		"With debug info" off \
		THREADS		"With pthreads" on \
		GNUTLS 		"With SSL (via GnuTLS) for SWAT support" off \
		EXT_TDB		"With external libtdb" on \
		EXT_TALLOC	"With external libtalloc" on \
		EXT_TEVENT	"With external libtevent" on \
		POPT		"With system-wide POPT library" on \
		PCH		"With precompiled headers" off

.endif

.include <bsd.port.pre.mk>

.if !defined(SAMBA_SUBPORT)
#
USE_RC_SUBR=		${SAMBA_PORTNAME}
SUB_FILES=		pkg-message

CONFIGURE_ARGS+=	\
			--disable-external-heimdal \
			--with-setproctitle \
			--with-readline=/usr \
			--with-libiconv=${LOCALBASE}
# backtrace
LIB_DEPENDS+=		execinfo.1:${PORTSDIR}/devel/libexecinfo
# BLKID
LIB_DEPENDS+=		blkid.1:${PORTSDIR}/misc/e2fsprogs-libblkid
# SASL
LIB_DEPENDS=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2

.if defined(WITH_DSO)
CONFIGURE_ARGS+=	--enable-dso
.else
CONFIGURE_ARGS+=	--disable-dso
.endif

.if !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--enable-debug --enable-developer \
			--enable-socket-wrapper --enable-nss-wrapper
.else
CONFIGURE_ARGS+=	--disable-debug --disable-developer \
			--disable-socket-wrapper --disable-nss-wrapper
.endif

.if !defined(WITHOUT_THREADS)
CPPFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LIBS}
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-pthreads
.else
CONFIGURE_ARGS+=	--without-pthreads
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls.26:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if !defined(WITHOUT_POPT)
LIB_DEPENDS+=		popt.0:${PORTSDIR}/devel/popt
CONFIGURE_ARGS+=	--without-included-popt
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

.if defined(WITH_SQLITE3)
USE_SQLITE=		3
CONFIGURE_ARGS+=	--with-sqlite3
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if defined(WITH_EXT_TDB)
LIB_DEPENDS+=		tdb.1:${PORTSDIR}/databases/tdb
CONFIGURE_ARGS+=	--enable-external-libtdb
PLIST_SUB+=		TDB="@comment "
.else
CONFLICTS+=		tdb-1*
CONFIGURE_ARGS+=	--disable-external-libtdb
PLIST_SUB+=		TDB=""
.endif

.if defined(WITH_EXT_TALLOC)
LIB_DEPENDS+=		talloc.1:${PORTSDIR}/devel/talloc
CONFIGURE_ARGS+=	--enable-external-libtalloc
.else
CONFLICTS+=		talloc-1*
CONFIGURE_ARGS+=	--disable-external-libtalloc
.endif

.if defined(WITH_EXT_TEVENT)
LIB_DEPENDS+=		tevent.0:${PORTSDIR}/devel/tevent
CONFIGURE_ARGS+=	--enable-external-libtevent
PLIST_SUB+=		TEVENT="@comment "
.else
CONFLICTS+=		tevent-0*
CONFIGURE_ARGS+=	--disable-external-libtevent
PLIST_SUB+=		TEVENT=""
.endif

.if defined(SAMBA_DISABLE_EXT) && !empty(SAMBA_DISABLE_EXT)
CONFIGURE_ARGS+=	--with-disable-ext-lib="${SAMBA_DISABLE_EXT:Q:C/(\\\\ )+/,/g}"
.endif

SAMBA_SUB=		SAMBA_LOGDIR="${SAMBA_LOGDIR}" \
			SAMBA_LOCKDIR="${SAMBA_LOCKDIR}" \
			SAMBA_CONFDIR="${SAMBA_CONFDIR}" \
			SAMBA_CONFIG="${SAMBA_CONFIG}" \
			SAMBA_RUNDIR="${SAMBA_RUNDIR}" \
			SAMBA_PRIVATEDIR="${SAMBA_PRIVATEDIR}"

PLIST_SUB+=		${SAMBA_SUB}
SUB_LIST+=		${SAMBA_SUB}

.if defined(WITH_PCH)
pre-build:
	(cd ${BUILD_WRKSRC} && ${GMAKE} pch)
.endif

post-build:
.for f in autoidl epdump fullschema get-descriptors minschema mymachinepw rpcclient samba3dump smbstatus subunitrun
	@${REINPLACE_CMD} -i '' -e '1,1 s|#!.*python.*|#!${PYTHON_CMD}|' \
		${WRKSRC}/scripting/bin/${f}
.endfor
.for f in enableaccount newuser provision provision-backend setexpiry setpassword upgrade
	@${REINPLACE_CMD} -i '' -e '1,1 s|#!.*python.*|#!${PYTHON_CMD}|' \
		${WRKSRC}/setup/${f}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}
# !SAMBA_SUBPORT
.endif

.include <bsd.port.post.mk>
