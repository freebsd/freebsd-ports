# New ports collection makefile for:	pinentry
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	pinentry
PORTVERSION=	0.6.9
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.klaralvdalens-datakonsult.se/pub/aegypten/alpha/latest/ \
		${MASTER_SITE_GNUPG} \
		http://tigress.com/lofi/:lofi
MASTER_SITE_SUBDIR=	alpha/aegypten
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		common.tar.gz:lofi\
		jnlib.tar.gz:lofi

MAINTAINER=	lofi@freebsd.org
COMMENT=	A collection of simple PIN or passphrase entry dialogs

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt \
		ksba.7:${PORTSDIR}/security/libksba

USE_GETOPT_LONG=yes
USE_AUTOMAKE_VER=	15
WANT_GNOME=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=--with-included-gettext=no
INFO=		pinentry

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/moc)
WITH_QT=yes
.endif

.if defined(WITH_QT)
USE_QT_VER=	3
PLIST_SUB+=	WITH_QT=""
.else
CONFIGURE_ARGS+=--disable-pinentry-qt
PLIST_SUB+=	WITH_QT="@comment "
.endif

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PLIST_SUB+=	WITH_GTK=""
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk
PLIST_SUB+=	WITH_GTK="@comment "
.endif

post-extract:
	${MV} ${WRKDIR}/common ${WRKSRC}
	${MV} ${WRKDIR}/jnlib ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	cd ${WRKSRC}; ./autogen.sh

.include <bsd.port.post.mk>
