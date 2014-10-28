# Created by: Tony Shadwick <tshadwick@oss-solutions.com>
# $FreeBSD$

PORTNAME=	htop
PORTVERSION=	1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://hisham.hm/htop/releases/${PORTVERSION}/

MAINTAINER=	gaod@hychen.org
COMMENT=	Better top(1) - interactive process viewer

LICENSE=	GPLv2

OPTIONS_DEFINE=	LSOF
OPTIONS_DEFAULT=LSOF

NOT_FOR_ARCHS=	ia64 powerpc sparc64

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo

CONFIGURE_ARGS=	--with-proc=/compat/linux/proc --enable-unicode
USES=		ncurses libtool execinfo python:build
USE_AUTOTOOLS=	autoconf aclocal automake
ACLOCAL_ARGS=	-I ${ACLOCAL_DIR}

LSOF_RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/bin/python:${PYTHON_CMD}:' ${WRKSRC}/scripts/MakeHeader.py

pre-configure:
	@[ -f /compat/linux/proc/stat ] || { ${CAT} ${PKGMESSAGE}; ${FALSE}; }

.include <bsd.port.mk>
