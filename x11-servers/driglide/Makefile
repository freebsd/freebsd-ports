# New ports collection makefile for:	glide3
# Date created:				31 Mar 2001
# Whom:					Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	driglide
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= anholt/driglide/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries to support 3dfx Voodoo3/4/5/Banshee with the DRI

USE_BZIP2=		yes
USE_X_PREFIX=		yes
XFREE86_VERSION=	4
INSTALLS_SHLIB=		yes
USE_LIBTOOL=		yes
USE_AUTOMAKE_VER=	14
AUTOMAKE_ARGS=		-a
USE_GMAKE=		yes
# Not yet ported to Alpha.
ONLY_FOR_ARCHS=		i386

# Glide DOES NOT work with CFLAGS greater than -O2
CFLAGS+= -O

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-extract:
	cd $(WRKSRC) && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal

.include <bsd.port.post.mk>
