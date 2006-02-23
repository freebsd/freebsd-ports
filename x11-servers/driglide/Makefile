# New ports collection makefile for:	glide3
# Date created:				31 Mar 2001
# Whom:					Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	driglide
PORTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anholt/driglide/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries to support 3dfx Voodoo3/4/5/Banshee with the DRI

USE_BZIP2=		yes
USE_X_PREFIX=		yes
INSTALLS_SHLIB=		yes
USE_AUTOTOOLS=	automake:14 autoconf:253 libtool:15
AUTOMAKE_ARGS=		-a
USE_GMAKE=		yes
MAKE_ARGS=		PREPROCESSOR=/usr/bin/cpp
# Not yet ported to Alpha.
ONLY_FOR_ARCHS=		i386

# Glide DOES NOT work with CFLAGS greater than -O2
CFLAGS+=	-O

pre-configure:
	@cd $(WRKSRC) && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal
	@${REINPLACE_CMD} -e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
