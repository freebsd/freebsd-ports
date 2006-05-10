# New ports collection makefile for:	libsrs
# Date created:		28 February 2004
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	libsrs
PORTVERSION=	0.3.b
CATEGORIES=	mail
MASTER_SITES=	http://www.libsrs.org/files/
DISTNAME=	${PORTNAME}.${PORTVERSION}eta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sender Rewriting Scheme (SRS) library and client

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}.3
USE_GMAKE=	yes
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes
LIBSRS_REV=	1
PLIST_SUB=	PORTNAME=${PORTNAME} LIBSRS_REV=${LIBSRS_REV}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${OPENSSLINC}" \
		LDFLAGS="${LDFLAGS} -L${OPENSSLLIB} -L${WRKSRC}"

# WITH_SRS_DEBUG=yes	enable debugging
.if defined(WITH_SRS_DEBUG)
SRS_CFLAGS=	-ggdb3 -DDEBUG
.endif

# This is all a bit messy, but given the inconvenient original Makefile,
# this seems to be the best way to make this port work in this version.
# The author of libsrs is working on autotools support, so this ugliness
# should have an end soon.
post-patch:
	@${REINPLACE_CMD} \
	  -e 's/^CFLAGS:=.*/CFLAGS+=-Wall -D_USE_BSD_SOURCE ${SRS_CFLAGS}/' \
	  -e 's/^CPPFLAGS:=/#CPPFLAGS:=/' \
	  -e 's/^LDFLAGS:=/#LDFLAGS:=/' \
	  -e 's/cd tools; make static; make ins.all/cd tools; make shared/g' \
	  -e 's/make/gmake/g' \
	  -e 's/libsrs.a : -lcrypto /libsrs.a : /g' \
	  -e 's/libsrs\.so\.1\.0\.1/libsrs.so.${LIBSRS_REV}/g' \
	  -e 's/-soname,libsrs\.so\.1/-soname,libsrs.so.${LIBSRS_REV}/g' \
	  ${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
	  -e 's/^CFLAGS:=/#CFLAGS:=/' \
	  -e 's/^CPPFLAGS:=/#CPPFLAGS:=/' \
	  -e 's/^LDFLAGS:=/#LDFLAGS:=/' \
	  -e 's/make/gmake/g' \
	  -e 's/mv static srs/mv static srs-${PORTNAME}/g' \
	  -e 's/mv shared srs/mv shared srs-${PORTNAME}/g' \
	  -e 's/libsrs\.so\.1\.0\.1/libsrs.so.${LIBSRS_REV} -lcrypto/g' \
	  ${WRKSRC}/tools/Makefile
	@${REINPLACE_CMD} \
	  -e 's/compile with -DDEBUG/build with WITH_SRS_DEBUG=yes/g' \
	  ${WRKSRC}/tools/srs.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/srs.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libsrs.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libsrs.so.${LIBSRS_REV} ${PREFIX}/lib
	(cd ${PREFIX}/lib ; ${LN} -sf libsrs.so.${LIBSRS_REV} libsrs.so)
	${INSTALL_PROGRAM} ${WRKSRC}/tools/srs-${PORTNAME} ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
