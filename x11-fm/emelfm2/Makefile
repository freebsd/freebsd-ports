# New ports collection makefile for:   emelfm2
# Date created:        01 Novemeber 2003
# Whom:                Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	emelfm2
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.emelfm2.org/rel/

MAINTAINER=	mva@sysfault.org
COMMENT=	The gtk2 port of emelfm, a fast graphical filemanager

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
INSTALLS_SHLIB=	yes

MAKE_ENV=	CC=${CC} LDFLAGS="${LDFLAGS}" DOC_DIR="${DOCSDIR}"

PLUGINDIR=	${WRKSRC}/objs/plugins
PLUGINS=	e2p_clone.so e2p_cpbar.so e2p_du.so e2p_find.so \
		e2p_for_each.so e2p_glob.so e2p_mvbar.so e2p_names_clip.so \
		e2p_pack.so e2p_rename_ext.so e2p_sort_by_ext.so \
		e2p_upgrade.so e2p_unpack.so e2p_view.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

.include <bsd.port.post.mk>
