# New ports collection makefile for:		xdelta
# Version required:				1.0.2
# Date created:					Sun May  4 21:40:06 CDT 1997
# Whom:						jmacd
#
# $Id: Makefile,v 1.11 1998/09/22 16:43:30 vanilla Exp $
#

DISTNAME=	xdelta-1.0.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=	jmacd@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	glib11d.2:${PORTSDIR}/devel/glib11-devel

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS=-L${LOCALBASE}/lib \
		INSTALL_SCRIPT='$${INSTALL} -m 755' \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config"

MAN1=           xdelta.1

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>
