# New ports collection makefile for:	gtk-gnutella
# Date created:				19 May, 2000
# Whom:					rbt@zort.on.ca
#
# $FreeBSD$
#

#
# A quick note on configurable make symbols:
#
# WITH_INTERACTIVE: Launches Configure in it's default mode, which is *very*
#	interactive. Disabled here by default to conform to FreeBSD guidelines,
#	this mode is useful if you have problems with the default Configure.
#
# WITH_GTK2: Configure and build for gtk2.
#
# WITH_PORTABILITY: Configure code to use the PATH variable at run-time
#	at a cost in performance. Useful if you intend to move the executable
#	to multiple machines.
#
# WITH_DEBUG: Compile with debugging symbols. Useful if you intend to make a bug
#	report.
#
# Note that unicode support is currently unavailable for this platform. This
# package requires a working ICU installation to achieve this, which doesn't
# work here, and produces a broken executable.
#

PORTNAME=	gtk-gnutella
PORTVERSION=	0.93.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://gtk-gnutella.sourceforge.net/download/ \
		ftp://gtk-gnutella.sourceforge.net/pub/gtk-gnutella/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	crollins666@hotmail.com
COMMENT=	GTK based Gnutella client

MAN1=		gtk-gnutella.1

USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GNOME=	libxml2
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-Dyacc='bison -y' -Dofficial='true' -Dprefix=${PREFIX}
CONFIGURE_ARGS+=	-Dbindir=${PREFIX}/bin -Dprivlib=${PREFIX}/share/gtk-gnutella
CONFIGURE_ARGS+=	-Dsysman=${PREFIX}/man/man1 -Dlocale=${PREFIX}/share/locale
CONFIGURE_ARGS+=	-Dccflags='${CFLAGS} -I${LOCALBASE}/include/'

OPTIONS=	DEBUG "Build with debugging symbols" off\
		GTK2 "Build with gtk2 frontend" off \
		INTERACTIVE "Use Configure in interactive mode" off \
		PORTABILITY "Use the PATH variable at run-time" off

.include <bsd.port.pre.mk>

.if !defined(WITH_INTERACTIVE)
CONFIGURE_ARGS+=-d -e
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

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	-Doptimize=-g  -Uofficial=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| icuuc | |' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${ECHO} 'Installing compressed man page in man/man1/'
	@${CP} ${WRKSRC}/src/gtk-gnutella.man ${WRKSRC}/src/gtk-gnutella.1
	@${INSTALL_MAN} ${WRKSRC}/src/gtk-gnutella.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
