# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsnmptools
PORTVERSION=	0.0.20060818
DISTVERSION=	20060818-01
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.ringlet.net/~shteryana/snmp/ CENKES
EXTRACT_SUFX=	.tar

MAINTAINER=	unixmania@gmail.com
COMMENT=	Snmp client tools

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	SHLIB_MAJOR=0 INCLUDEDIR=${PREFIX}/include LIBDIR=${PREFIX}/lib \
		MANDIR=${MANPREFIX}/man/man NO_MANCOMPRESS=yes BINDIR=${PREFIX}/bin \
		NO_PROFILE=yes
CFLAGS=		-I${WRKSRC}/lib -L${WRKSRC}/lib
PLIST_FILES=	${BIN_FILES:S,^,bin/,} include/${PORTNAME}.h include/bsnmptc.h \
		lib/lib${PORTNAME}.a lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0
BIN_FILES=	bsnmpget bsnmpset bsnmpwalk
MAN1=	${BIN_FILES:S/$/.1/}
MAN3=	${PORTNAME}.3

NO_STAGE=	yes
post-extract:
	@${CHMOD} -R u+w ${WRKSRC}
	@${MV} ${WRKSRC}/lib/libbsnmptools/libbsnmptools ${WRKSRC}/tlib
	@${MV} ${WRKSRC}/usr.sbin/bsnmpd/tools ${WRKSRC}/
	@${RM} -rf ${WRKSRC}/lib ${WRKSRC}/usr.sbin ${WRKSRC}/tools/Makefile.inc
	@${MV} ${WRKSRC}/tlib ${WRKSRC}/lib

post-patch:
	@${REINPLACE_CMD} -e 's/usr.sbin/tools/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
