# New ports collection makefile for:	lavaps
# Date created:		11-Oct-99
# Whom:			johnh@isi.edu
#
# $FreeBSD$
#

PORTNAME=	lavaps
PORTVERSION=	1.20
CATEGORIES=	sysutils
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	wjv@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500014
BROKEN=		Changes to process info structs returned by kernel renders \
		lavaps unbuildable - author has been made aware of this
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-tcl-ver=8.3 --with-tk-ver=8.3
USE_NEWGCC=	yes
MAN1=		lavaps.1

.include <bsd.port.post.mk>
