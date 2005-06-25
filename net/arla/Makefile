# New ports collection makefile for:	arla
# Date created:			09 Sep 1998
# Whom:				Peter Hawkins <thepish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arla
PORTVERSION=	0.40
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.stacken.kth.se/pub/arla/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free AFS client implementation

USE_XLIB=	yes
USE_RC_SUBR=	arla.sh
USE_INC_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"security/heimdal is broken"
.elif ${OSVERSION} < 600007
BROKEN=		"compiles but overwrites files from a dependency (security/heimdal)"
.else
BROKEN=		"does not compile"
.endif

.if !exists(/usr/src/sys/kern/vnode_if.src)
IGNORE=		requires kernel source
.endif

CONFIGURE_ARGS=	--with-roken=${LOCALBASE}

.if defined(WITHOUT_KRB5)
CONFIGURE_ARGS+=--without-krb5
.elif !defined(WITH_SYSTEM_HEIMDAL)
LIB_DEPENDS+=	krb5.20:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=--with-krb5=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-krb5=/usr
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=

MAKE_ENV+=	OSVERSION=${OSVERSION}

MAN1=		afstool.1 arla-send-pr.1 kalog.1 pts.1 rxdebug.1 \
		tokens.1 udebug.1
MAN3=		log_close.3 log_get_mask.3 \
		log_log.3 log_mask2str.3 log_open.3 log_set_mask.3 \
		log_set_mask_str.3 log_unit_free.3 log_unit_init.3 \
		log_vlog.3
MAN5=		AliasDB.5 CellServDB.5 DynRootDB.5 SuidCells.5 \
		ThisCell.5 arla.conf.5
MAN8=		arla-cli.8 arlad.8 vos.8

.if defined(WITHOUT_NNPFS)
CONFIGURE_ARGS+=--disable-nnpfs
PLIST_SUB+=	NNPFS="@comment "
.else
PLIST_SUB+=	NNPFS=""
MAN4=		nnpfs.4
MAN8+=		mount_nnpfs.8 umount_nnpfs.8
.endif

INFO=		arla send-pr

.include <bsd.port.post.mk>
