# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	uhidd
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	REL-
PORTREVISION=	5
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	3ddfebf75bbb.patch:-p1
PATCHFILES+=	9c0b5e3255ec.patch:-p1
PATCHFILES+=	0d05cd7acadd.patch:-p1
PATCHFILES+=	c040f483add2.patch:-p1
PATCHFILES+=	d5af7099c1e9.patch:-p1
PATCHFILES+=	e9e835c93f53.patch:-p1
PATCHFILES+=	2ed68916f23b.patch:-p1
PATCHFILES+=	dd1279592b04.patch:-p1
PATCHFILES+=	498422ccef03.patch:-p1
PATCHFILES+=	7022ca4d1a1b.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userland USB HID device driver using libusb20

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	kaiwang27

USES=		uidfix
MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/share/man/man"
MAKE_ARGS=	LIBDIR="${LOCALBASE}/lib"
USE_RC_SUBR=	uhidd

OPTIONS_DEFINE=	DEVD
OPTIONS_DEFAULT=	DEVD
OPTIONS_SUB=	yes

.if defined(DEBUG_FLAGS)
MAKE_ENV+=	DEBUG_FLAGS='${DEBUG_FLAGS}'
.endif

post-patch:	.SILENT
	${FIND} ${WRKSRC}/uhidd -type f -not -name Makefile \
		-exec ${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' {} +

post-install-DEVD-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${REINPLACE_CMD} ${_SUB_LIST_TEMP} \
		${WRKSRC}/uhidd/uhidd-devd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/uhidd/uhidd-devd.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
