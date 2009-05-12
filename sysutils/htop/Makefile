# New ports collection makefile for:	htop
# Date created:		27 August 2007
# Whom:			Tony Shadwick <tshadwick@oss-solutions.com>
#
# $FreeBSD$
#

PORTNAME=	htop
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A better top(1) - interactive process viewer

NOT_FOR_ARCHS=	sparc64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-proc=/compat/linux/proc --enable-unicode
USE_AUTOTOOLS=	autoconf:262 aclocal:19 automake:19 libtool:15
ACLOCAL_ARGS=	-I ${ACLOCAL_DIR}

USE_PYTHON_BUILD=	yes

MAN1=	htop.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/bin/python:${LOCALBASE}/bin/python:' ${WRKSRC}/scripts/MakeHeader.py

pre-configure:
	@[ -f /compat/linux/proc/stat ] || { ${CAT} ${PKGMESSAGE}; ${FALSE}; }

.include <bsd.port.post.mk>
