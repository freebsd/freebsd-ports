# New ports collection makefile for:   netembryo
# Date created:        7 November 2007
# Whom:                Emmanuel Richiardone (err@tollari.org)
#
# $FreeBSD$
#

PORTNAME=	netembryo
PORTVERSION=	0.0.4
CATEGORIES=	net
MASTER_SITES=	http://live.polito.it/files/downloads/netembryo/

MAINTAINER=	err@tollari.org
COMMENT=	A network abstraction library used by for feng, libnemesi, felix

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig gnomehack

OPTIONS=	SCTP "Don't check if SCTP is present" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700028 && ! defined(WITH_SCTP)
IGNORE=		sorry, please use FreeBSD 7.x or patch your system for SCTP (http://www.sctp.org/download.html) and use WITH_SCTP=YES
.endif

.include <bsd.port.post.mk>
