# New ports collection makefile for: neon
# Date created:		13 October 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neon
PORTVERSION=	0.7.5
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat \
		xml:${PORTSDIR}/textproc/libxml

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} --with-expat=${PREFIX}/include/xml \
		--with-extra-libs=${PREFIX}/lib

ALL_TARGET=	all examples
INSTALL_TARGET=	install install-examples

.ifdef WITH_NBROWSE
LIB_DEPENDS+=	glade:${PORTSDIR}/devel/libglade
CONFIGURE_ARGS+=--with-libglade-config=${PREFIX}/bin/libglade-config \
		--with-gnome=${X11BASE} \
		--enable-gnome-examples
CONFIGURE_ENV+=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
ALL_TARGET+=	nbrowse
PLIST_SUB+=	GUI=''
.else
PLIST_SUB+=	GUI='@comment '

post-extract:
	# You can also build a GUI-sample application by doing:
	#	make -DWITH_NBROWSE
	# It is disabled by default, because the author thinks
	# it is BUGGY and because it requires libglade and GNOME.
.endif

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${PREFIX}/share/doc/neon
	${INSTALL_DATA} ${WRKSRC}/doc/using-neon.txt ${PREFIX}/share/doc/neon
PLIST_SUB+=	DOCS=''
.else
PLIST_SUB+=	DOCS='@comment '
.endif

.include <bsd.port.mk>
