# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	uhidd
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE \
		http://people.freebsd.org/~kaiw/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userland USB HID device driver using libusb20

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	cuse4bsd-kmod>=0.1.24:${PORTSDIR}/multimedia/cuse4bsd-kmod
LIB_DEPENDS=	libcuse4bsd.so:${PORTSDIR}/multimedia/cuse4bsd-kmod

USE_RC_SUBR=	uhidd
SUB_FILES=	pkg-message

LIBDIR=		${PREFIX}/lib

OPTIONS_DEFINE=	DEVD
OPTIONS_DEFAULT=	DEVD
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

LIBCUSE=	${LIBDIR}/libcuse4bsd.so

.if defined(DEBUG_FLAGS)
MAKE_ENV+=	DEBUG_FLAGS='${DEBUG_FLAGS}'
.endif

.if ${OSVERSION} > 1000012
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-uhidd-parser.y
.endif

post-patch:	.SILENT
	${FIND} ${WRKSRC}/uhidd -type f -not -name Makefile \
		-exec ${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' {} +

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhidd/uhidd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/uhidd/uhidd.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/uhidd/uhidd.conf.5 ${STAGEDIR}${PREFIX}/man/man5
.if ${PORT_OPTIONS:MDEVD}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${REINPLACE_CMD} -E \
		-e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%LIBCUSE%%|${LIBCUSE}|" \
		${WRKSRC}/uhidd/uhidd-devd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/uhidd/uhidd-devd.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd
.endif

.include <bsd.port.post.mk>
