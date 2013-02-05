# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	gxditview
PORTVERSION=	${GXDVVERSION}${GXDVREVISION}
PORTREVISION=	3
CATEGORIES=	textproc
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 based previewer for groff output

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

MAN1=		gxditview.1
PLIST_FILES=	bin/gxditview lib/X11/app-defaults/GXditview
NO_PACKAGE=	requires system sources in sync

BROKEN=	doesn't compile

.include <bsd.port.options.mk>

.if !exists(${SRC_BASE}/contrib/groff/src)
IGNORE=		requires ${SRC_BASE}/contrib/groff/src to build
GXDVVERSION=	1.16
GXDVREVISION=	.1
.else
GXDVVERSION!=	cat ${SRC_BASE}/contrib/groff/VERSION
GXDVREVISION!=	sed -e 's/^0$$//' -e 's/^[1-9].*$$/.&/' ${SRC_BASE}/contrib/groff/REVISION
.endif

.if exists(${SRC_BASE}/contrib/groff/src/devices/xditview) && \
    exists(${SRC_BASE}/gnu/usr.bin/groff/src/devices/xditview)
USE_XORG=	x11 xproto xt xmu xaw
MANCOMPRESSED=	maybe
WRKSRC=		${SRC_BASE}/gnu/usr.bin/groff/src/devices/xditview
MAKE_ENV=	MAKEOBJDIR=${WRKDIR}

pre-configure-script:
	@${DO_NADA}
.elif exists(${SRC_BASE}/contrib/groff/src/xditview)
USE_IMAKE=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	${CP} -rp ${SRC_BASE}/contrib/groff/src/xditview/* ${WRKSRC}
.endif

.include <bsd.port.mk>
