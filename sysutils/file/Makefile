# New ports collection makefile for:	file
# Date created:		2001-11-10
# Whom:			Jason Harris <jharris@widomaker.com>
#
# $FreeBSD$
#

PORTNAME=	file
PORTVERSION=	4.10
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.gw.com/mirrors/pub/unix/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	jharris@widomaker.com
COMMENT=	File - determine file type

USE_INC_LIBTOOL_VER=13
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-fsect-man5
MAN1=		file.1
MAN3=		libmagic.3
MAN5=		magic.5

INSTALLS_SHLIB=	yes

# The rules below are required to suppress invocations of aclocal, automake,
# autoconf and autoheader at `make build' and `make install'.

post-extract:
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/aclocal.m4
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/Makefile.in
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/stamp-h.in

.include <bsd.port.pre.mk>

# FreeBSD 4.x don't have mbrtowc and wcwidth implemented
.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's|ifdef HAVE_WCHAR_H|if 0|' ${WRKSRC}/src/file.c
.endif

.include <bsd.port.post.mk>
