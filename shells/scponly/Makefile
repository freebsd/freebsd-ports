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
# WITH_SCPONLY_WILDCARDS
# default: undefined
# define if you want to enable wildcard processing.
#
# WITH_SCPONLY_SCP
# default: undefined
# define if you want to enable vanilla scp compatibility.
#
# WITH_SCPONLY_GFTP
# default: undefined
# define if you want to enable gftp compatibility.
#
# WITH_SCPONLY_WINSCP
# default: undefined
# define if you want to enable WinSCP compatibility.
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
CATEGORIES=	shells
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rushani@FreeBSD.org
COMMENT=	A tiny shell that only permits scp and sftp

MAN8=		scponly.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-chrooted-binary

.include <bsd.port.pre.mk>

.if defined(WITH_SCPONLY_WILDCARDS)
CONFIGURE_ARGS+=--enable-wildcards
.else
CONFIGURE_ARGS+=--disable-wildcards
.endif

.if defined(WITH_SCPONLY_SCP)
CONFIGURE_ARGS+=--enable-scp-compat
.else
CONFIGURE_ARGS+=--disable-scp-compat
.endif

.if defined(WITH_SCPONLY_GFTP)
CONFIGURE_ARGS+=--enable-gftp-compat
.else
CONFIGURE_ARGS+=--disable-gftp-compat
.endif

.if defined(WITH_SCPONLY_WINSCP)
CONFIGURE_ARGS+=--enable-winscp-compat
.else
CONFIGURE_ARGS+=--disable-winscp-compat
.endif

.if defined(WITH_SCPONLY_RSYNC) && exists(${LOCALBASE}/bin/rsync)
CONFIGURE_ARGS+=--enable-rsync-compat
.else
CONFIGURE_ARGS+=--disable-rsync-compat
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/scponly
.for i in README INSTALL TODO
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/scponly
.endfor
.endif

.include <bsd.port.post.mk>
