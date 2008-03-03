# ports collection makefile for:	nagcon
# Date created:			Wed Mar 29 20:41:02 CST 2006
# Whom:				Douglas K. Rand <rand@meridian-enviro.com>
#
# $FreeBSD$
#

PORTNAME=	nagcon
PORTVERSION=	0.0.26
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.vanheusden.com/nagcon/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt
EXTRACT_SUFX=	.tgz

MAINTAINER=	rand@meridian-enviro.com
COMMENT=	Nagios console monitor

LIB_DEPENDS=	strfunc.9:${PORTSDIR}/devel/libstrfunc

PLIST_FILES=	bin/nagcon

CFILES=		error.c
CPPFILES=	utils.cpp br.cpp nc.cpp pl.cpp

CFLAGS+=	-DVERSION=\"${PORTVERSION}\" -I${LOCALBASE}/include
LDFLAGS+=	-lncurses -lstdc++ -L${LOCALBASE}/lib -lstrfunc

do-build:
	${CC} ${CFLAGS} -c -o ${WRKSRC}/${CFILES:C/\.c//}.o ${WRKSRC}/${CFILES}
.for f in ${CPPFILES}
	${CXX} ${CFLAGS} -c -o ${WRKSRC}/${f:C/\.cpp//}.o ${WRKSRC}/${f}
.endfor
	${CC} ${LDFLAGS} ${WRKSRC}/error.o ${CPPFILES:C/(.*)\.cpp/${WRKSRC}\/\1.o/} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
