# New ports collection makefile for:   emelfm2
# Date created:        01 Novemeber 2003
# Whom:                Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	emelfm2
PORTVERSION=	0.0.9
CATEGORIES=	x11-fm
MASTER_SITES=	http://dasui.prima.de/~tooar/

MAINTAINER=	mva@sysfault.org
COMMENT=	The gtk2 port of emelfm, a fast graphical filemanager

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
INSTALLS_SHLIB=	yes

MAKE_ENV=	CC=${CC} LDFLAGS="${LDFLAGS}" DOCSDIR="${DOCSDIR}"

PLUGINDIR=	${WRKSRC}/objs/plugins
PLUGINS=	cdburner.so clone.so copy_to_clipboard.so cpbar.so du.so for_each.so \
		glob.so mvbar.so pack.so rename_ext.so sort_by_ext.so unpack.so view.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.3
.endif

.if defined(NOPORTDOCS)
do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.for pfile in ${PLUGINS}
	@${MKDIR} ${PREFIX}/lib/emelfm2/plugins
	${INSTALL_PROGRAM} ${PLUGINDIR}/${pfile} ${PREFIX}/lib/emelfm2/plugins
.endfor
.endif

.include <bsd.port.post.mk>
