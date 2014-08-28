# $FreeBSD$

PORTNAME=	pond
PORTVERSION=	20140120
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://c-s.li/ports/
DISTFILES=	pond-20140120.tar.gz \
		go-gtk-20131128.tar.gz \
		ed25519-20131225.tar.gz

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Forward secure, asynchronous messenger

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.crypto/bcrypt.a:${PORTSDIR}/security/go.crypto \
		${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/goprotobuf/proto.a:${PORTSDIR}/devel/goprotobuf \
		${LOCALBASE}/${GO_LIBDIR}/code.google.com/p/go.net/dict.a:${PORTSDIR}/net/go.net
RUN_DEPENDS=	tor:${PORTSDIR}/security/tor
LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell \
		libtspi.so:${PORTSDIR}/security/trousers

IGNORE=		Experimental. Know what you do!
PLIST_FILES=	bin/server bin/client
USE_GNOME=	gtk30
GO_PKGNAME=	github.com/agl/pond
GO_TARGET=	${GO_PKGNAME}/server \
		${GO_PKGNAME}/client

post-extract:
	@${MKDIR} ${GO_WRKSRC:H}
	@${CP} files/sys_freebsd.go ${WRKSRC}/client/system/sys_freebsd.go
	@${CP} files/main_freebsd.go ${WRKSRC}/client/main_freebsd.go
	@${LN} -sf ${WRKSRC} ${GO_WRKSRC}
	@${LN} -sf ${WRKDIR}/go-gtk-20131128 ${GO_WRKDIR_SRC}/github.com/agl/go-gtk
	@${LN} -sf ${WRKDIR}/ed25519-20131225 ${GO_WRKDIR_SRC}/github.com/agl/ed25519

post-patch:
	@${REINPLACE_CMD} -e 's|\<gdk|\<gtk-3.0\/gdk|g' \
		${WRKDIR}/go-gtk-20131128/gdk/gdk.go \
		${WRKDIR}/go-gtk-20131128/gdk/gdk_linux.go \
		${WRKDIR}/go-gtk-20131128/gdk/gdk_windows.go \
		${WRKDIR}/go-gtk-20131128/gtk/gtk.go
	@${REINPLACE_CMD} -e 's|\<pango|\<pango-1.0\/pango|g' \
		${WRKDIR}/go-gtk-20131128/pango/pango.go
	@${REINPLACE_CMD} -e 's|\<gtk|\<gtk-3.0\/gtk|g' \
		${WRKDIR}/go-gtk-20131128/gtk/gtk.go \
		${WRKDIR}/go-gtk-20131128/gtkspell/gtkspell_fedora.go \
		${WRKDIR}/go-gtk-20131128/gtkspell/gtkspell_ubuntu.go
	@${REINPLACE_CMD} -e 's|\<glib|\<glib-2.0\/glib|g' \
		${WRKDIR}/go-gtk-20131128/glib/glib.go
	@${REINPLACE_CMD} -e 's|\<gdk-pixbuf|\<gdk-pixbuf-2.0\/gdk-pixbuf|g' \
		${WRKDIR}/go-gtk-20131128/gdkpixbuf/gdkpixbuf.go
	@${REINPLACE_CMD} -e 's|\<gtkspell|\<gtkspell-2.0\/gtkspell|g' \
		${WRKDIR}/go-gtk-20131128/gtkspell/gtkspell_fedora.go \
		${WRKDIR}/go-gtk-20131128/gtkspell/gtkspell_ubuntu.go

do-build:
	@(cd ${GO_WRKSRC}; ${SETENV} ${GO_ENV} ${GO_CMD} install -tags nogui -v ${GO_TARGET})

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
