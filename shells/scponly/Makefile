# New ports collection makefile for:	scponly
# Date created:				2002/07/23
# Whom:					mcglk@artlogix.com
#
# $FreeBSD$
#

# There are many knobs to tune scponly towards your specific wishes
# and preferences.
# You can activate a knob by typing something like
# "make -DKNOB" or "make KNOB=yes" instead of just "make"
#
# A description of the several possibilities is available here:
#
#
# Core funcionality:
#
# WITHOUT_SCPONLY_WILDCARDS
# default: undefined
# define if you want to disable wildcard processing.
#
# WITHOUT_SCPONLY_SCP
# default: undefined
# define if you want to disable vanilla scp compatibility.
#
# WITHOUT_SCPONLY_GFTP
# default: undefined
# define if you want to disable gftp compatibility.
#
# WITHOUT_SCPONLY_WINSCP
# default: undefined
# define if you want to disable WinSCP compatibility.
#
# WITH_SCPONLY_CHROOT
# default: undefined
# define if you want to use chroot functionality (set UID to root).
#
# WITH_SCPONLY_RSYNC
# default: undefined
# define if you want to enable rsync compatibility.
#
#
# Additional knobs:
#
# NOPORTDOCS
# default: undefined
# This knob prevents the ports system from installing additional
# documentation. If you define this, only the manpage is going
# to be installed.

PORTNAME=	scponly
PORTVERSION=	3.8
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rushani@FreeBSD.org
COMMENT=	A tiny shell that only permits scp and sftp

MAN8=		scponly.8

GNU_CONFIGURE=	yes
PLIST_SUB+=	SCPONLY_CHROOT="@comment "

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501105 && exists(/libexec/ld-elf.so.1)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-aa
.endif

.if defined(WITHOUT_SCPONLY_WILDCARDS)
CONFIGURE_ARGS+=--disable-wildcards
.endif

.if defined(WITHOUT_SCPONLY_SCP)
CONFIGURE_ARGS+=--disable-scp-compat
.endif

.if defined(WITHOUT_SCPONLY_GFTP)
CONFIGURE_ARGS+=--disable-gftp-compat
.endif

.if defined(WITHOUT_SCPONLY_WINSCP)
CONFIGURE_ARGS+=--disable-winscp-compat
.endif

.if defined(WITH_SCPONLY_CHROOT)
PLIST_SUB=	SCPONLY_CHROOT=""
CONFIGURE_ARGS+=--enable-chrooted-binary
.endif

.if defined(WITH_SCPONLY_RSYNC)
BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--enable-rsync-compat
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can enable chroot functionality by defining WITH_SCPONLY_CHROOT."
	@${ECHO_MSG} ""

post-install:
.if defined(WITH_SCPONLY_CHROOT)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Run following script to setup chroot cage;"
	@${ECHO_MSG} "${WRKSRC}/setup_chroot.sh"
	@${ECHO_MSG} ""
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README INSTALL TODO
	@${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
