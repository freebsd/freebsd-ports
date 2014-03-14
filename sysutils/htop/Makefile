# Created by: Tony Shadwick <tshadwick@oss-solutions.com>
# $FreeBSD$

PORTNAME=	htop
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	gaod@hychen.org
COMMENT=	Better top(1) - interactive process viewer

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

OPTIONS_DEFINE=	LSOF
OPTIONS_DEFAULT=LSOF

NOT_FOR_ARCHS=	ia64 powerpc sparc64

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lexecinfo"

CONFIGURE_ARGS=	--with-proc=/compat/linux/proc --enable-unicode
USES=		ncurses
USE_AUTOTOOLS=	autoconf aclocal automake libtool
ACLOCAL_ARGS=	-I ${ACLOCAL_DIR}

USE_PYTHON_BUILD=	yes

LSOF_RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/bin/python:${PYTHON_CMD}:' ${WRKSRC}/scripts/MakeHeader.py

pre-configure:
	@[ -f /compat/linux/proc/stat ] || { ${CAT} ${PKGMESSAGE}; ${FALSE}; }

.include <bsd.port.mk>
