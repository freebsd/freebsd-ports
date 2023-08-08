PORTNAME=	xgas
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	SUNSITE/X11/demos
DISTNAME=	${PORTNAME}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	The animated simulation of an ideal gas

LICENSE=	MIT

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xt

PLIST_FILES=	bin/xgas lib/X11/app-defaults/XGas \
		man/man1/xgas.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
