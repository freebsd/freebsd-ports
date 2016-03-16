# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	uhidd
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	REL-
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Userland USB HID device driver using libusb20

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	kaiwang27

USES=		uidfix
MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man"
MAKE_ARGS=	LIBDIR="${LOCALBASE}/lib"
USE_RC_SUBR=	uhidd

OPTIONS_DEFINE=	CUSE DEVD
OPTIONS_DEFAULT=	DEVD
OPTIONS_SUB=	yes

.if exists(/usr/lib/libcuse.so)
OPTIONS_DEFAULT+=	CUSE
.else
OPTIONS_EXCLUDE+=	CUSE
.endif

CUSE_DESC=	Use cuse(3) over multimedia/cuse4bsd-kmod
CUSE_BUILD_DEPENDS_OFF=	cuse4bsd-kmod>=0.1.24:multimedia/cuse4bsd-kmod
CUSE_LIB_DEPENDS_OFF=	libcuse4bsd.so:multimedia/cuse4bsd-kmod
CUSE_SUB_LIST_OFF=	LIBCUSE="${LOCALBASE}/lib/libcuse4bsd.so"
CUSE_SUB_LIST=		LIBCUSE=""

.if defined(DEBUG_FLAGS)
MAKE_ENV+=	DEBUG_FLAGS='${DEBUG_FLAGS}'
.endif

post-patch:	.SILENT
	${FIND} ${WRKSRC}/uhidd -type f -not -name Makefile \
		-exec ${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' {} +

post-patch-CUSE-on: .SILENT
	${FIND} ${WRKSRC}/uhidd -type f -not \
		-exec ${REINPLACE_CMD} -i '.cuse.bak' \
		-Ee '/_init|\.c/!s|cuse4bsd|cuse|' {} +

post-install-DEVD-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${REINPLACE_CMD} ${_SUB_LIST_TEMP} \
		${WRKSRC}/uhidd/uhidd-devd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/uhidd/uhidd-devd.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
