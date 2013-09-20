# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	uhidd
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE \
		http://people.freebsd.org/~kaiw/distfiles/

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	Userland USB HID device driver using libusb20

BUILD_DEPENDS=	cuse4bsd-kmod>=0.1.24:${PORTSDIR}/multimedia/cuse4bsd-kmod
LIB_DEPENDS=	cuse4bsd:${PORTSDIR}/multimedia/cuse4bsd-kmod

OPTIONS_DEFINE=	DEVD
OPTIONS_DEFAULT=	DEVD

USE_RC_SUBR=	uhidd
SUB_FILES=	pkg-message

MAN5=		uhidd.conf.5
MAN8=		uhidd.8

LIBDIR=		${PREFIX}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

LIBCUSE=	${LIBDIR}/libcuse4bsd.so

.if defined(DEBUG_FLAGS)
MAKE_ENV+=	DEBUG_FLAGS='${DEBUG_FLAGS}'
.endif

.if ${OSVERSION} < 800069
IGNORE=		does not build with the old USB stack
.elif ${OSVERSION} > 1000012
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-uhidd-parser.y
.endif

.if ${PORT_OPTIONS:MDEVD}
PLIST_SUB+=	PL_DEVD=""
.else
PLIST_SUB+=	PL_DEVD="@comment "
.endif

post-patch:	.SILENT
	${FIND} ${WRKSRC}/uhidd -type f -not -name Makefile \
		-exec ${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' {} +

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhidd/uhidd ${PREFIX}/sbin/uhidd
	${INSTALL_MAN} ${WRKSRC}/uhidd/uhidd.8 ${PREFIX}/man/man8/uhidd.8
	${INSTALL_MAN} ${WRKSRC}/uhidd/uhidd.conf.5 ${PREFIX}/man/man5/uhidd.conf.5
.if ${PORT_OPTIONS:MDEVD}
	${MKDIR} ${PREFIX}/etc/devd
	${REINPLACE_CMD} -E \
		-e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%LIBCUSE%%|${LIBCUSE}|" \
		${WRKSRC}/uhidd/uhidd-devd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/uhidd/uhidd-devd.conf.sample ${PREFIX}/etc/devd/
	@if [ ! -f ${PREFIX}/etc/devd/uhidd-devd.conf ]; then \
		${CP} -p ${PREFIX}/etc/devd/uhidd-devd.conf.sample \
			${PREFIX}/etc/devd/uhidd-devd.conf; \
	fi
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
