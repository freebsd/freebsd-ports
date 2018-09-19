# Created by: Daniel Blankensteiner <db@TruNet.dk>
# $FreeBSD$

PORTNAME=	lockdown
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://lockdown.trunet.dk/ \
		http://lockdown.loproc.dk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hardening script for FreeBSD
FORBIDDEN=	Renders system unbootable
DEPRECATED=	Renders system unbootable
EXPIRATION_DATE=	2018-09-30

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/lockdown

CFLAGS_aarch64+=-fPIC
CFLAGS_amd64+=	-fPIC
CFLAGS_i386+=	-fPIC

do-install:
	${INSTALL_LIB} ${WRKSRC}/cppe/src/libcppe.so ${STAGEDIR}${PREFIX}/lib
.for f in editfile editfstab editkernel editlogin editttys
	${INSTALL_PROGRAM} ${WRKSRC}/edittools/${f}/src/${f} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/edittools/${f}/doc/${f}.1 \
		${STAGEDIR}${PREFIX}/man/man1
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/lockdown ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
