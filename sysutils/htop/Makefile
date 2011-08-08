# New ports collection makefile for:	htop
# Date created:		27 August 2007
# Whom:			Tony Shadwick <tshadwick@oss-solutions.com>
#
# $FreeBSD$
#

PORTNAME=	htop
PORTVERSION=	0.9
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	gaod@hychen.org
COMMENT=	A better top(1) - interactive process viewer

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

OPTIONS=	LSOF "Enable lsof support" On

NOT_FOR_ARCHS=	sparc64

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lexecinfo"

CONFIGURE_ARGS=	--with-proc=/compat/linux/proc --enable-unicode
USE_AUTOTOOLS=	autoconf aclocal automake libtool
USE_NCURSES=	yes
ACLOCAL_ARGS=	-I ${ACLOCAL_DIR}

USE_PYTHON_BUILD=	yes

MAN1=	htop.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LSOF)
RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/bin/python:${LOCALBASE}/bin/python:' ${WRKSRC}/scripts/MakeHeader.py

pre-configure:
	@[ -f /compat/linux/proc/stat ] || { ${CAT} ${PKGMESSAGE}; ${FALSE}; }

.include <bsd.port.post.mk>
