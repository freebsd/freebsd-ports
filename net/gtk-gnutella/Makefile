# New ports collection makefile for:	gtk-gnutella
# Date created:				19 May, 2000
# Whom:					rbt@zort.on.ca
#
# $FreeBSD$
#

#
# A quick note on configurable make symbols:
#
# INTERACTIVE_CONFIGURE: Launches Configure in its default mode,
#	which is *very* interactive. Disabled here by default to conform to
#	FreeBSD guidelines, this mode is useful if you have problems with the
#	default Configure.
#
# WITH_GTK2: Configure and build for gtk2.
#
# WITH_PORTABILITY: Configure code to use the PATH variable at run-time
#	at a cost in performance. Useful if you intend to move the executable
#	to multiple machines.
#
# WITH_DEBUG: Compile with debugging symbols. Useful if you intend to make
#	a bug report.
#

PORTNAME=	gtk-gnutella
PORTVERSION=	0.95.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://gtk-gnutella.sourceforge.net/download/ \
		ftp://gtk-gnutella.sourceforge.net/pub/gtk-gnutella/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jonas@schiebtsich.net
COMMENT=	GTK based Gnutella client

USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GNOME=	libxml2
INSTALL_TARGET=	install install.man
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-Dyacc='bison -y' -Dofficial='true' -Dprefix=${PREFIX} \
		-Dprivlib=${PREFIX}/share/gtk-gnutella \
		-Dsysman=${PREFIX}/man/man1 -Dlocale=${PREFIX}/share/locale \
		-Dcc='${CC}' -Dccflags='${CFLAGS} -I${LOCALBASE}/include' \
		-Doptimize='undef' -Dlibpth='/usr/lib ${LOCALBASE}/lib'

MAN1=		gtk-gnutella.1

OPTIONS=	DEBUG "Build with debugging symbols" off \
		GTK2 "Build with gtk2 frontend" on \
		PORTABILITY "Use the PATH variable at run-time" off

.include <bsd.port.pre.mk>

.if !defined(INTERACTIVE_CONFIGURE)
CONFIGURE_ARGS+=	-d -e
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	-Doptimize=-g  -Uofficial=
.endif

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=	-Dgtkversion=2
USE_GNOME+=		gtk20
.else
CONFIGURE_ARGS+=	-Dgtkversion=1
USE_GNOME+=		gtk12
.endif

.if defined(WITH_PORTABILITY)
CONFIGURE_ARGS+=	-Dd_portable=true
.endif

.include <bsd.port.post.mk>
