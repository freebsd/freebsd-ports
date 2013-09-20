# Created by: Damjan Jovanovic <damjan.jov@gmail.com>
# $FreeBSD$

PORTNAME=	prelink
PORTVERSION=	20111012
CATEGORIES=	sysutils
MASTER_SITES=	http://people.redhat.com/jakub/prelink/

MAINTAINER=	damjan.jov@gmail.com
COMMENT=	ELF prelinking utility to speed up dynamic linking

LIB_DEPENDS=	argp:${PORTSDIR}/devel/argp-standalone
BUILD_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize libtool
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-c -a
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/execstack \
		sbin/prelink

MAN8=		execstack.8 prelink.8

NO_STAGE=	yes
.include <bsd.port.mk>
