# New ports collection makefile for:		xdelta
# Version required:				1.0.2
# Date created:					Sun May  4 21:40:06 CDT 1997
# Whom:						jmacd
#
# $Id: Makefile,v 1.12 1999/02/20 10:47:28 vanilla Exp $
#

DISTNAME=	xdelta-1.0.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=	jmacd@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	glib12.1:${PORTSDIR}/devel/glib12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS=-L${LOCALBASE}/lib \
		INSTALL_SCRIPT='$${INSTALL} -m 755' \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config"

MAN1=           xdelta.1

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>
