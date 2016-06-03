# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	pcfclock
PORTVERSION=	0.44
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www-stud.ims.uni-stuttgart.de/~voegelas/pcfclock/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userland access to the pcfclock device

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USE_RC_SUBR=	pcfdate

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-linux

PLIST_FILES=	man/man8/pcfdate.8.gz sbin/pcfdate

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
IGNORE=		not supported for architecture ${ARCH}
.endif

.include <bsd.port.post.mk>
