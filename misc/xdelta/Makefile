# New ports collection makefile for:    xdelta
# Version required:     0.23
# Date created:         Sun May  4 21:40:06 CDT 1997
# Whom:                 jmacd
#
# $Id: Makefile,v 1.10 1998/09/03 00:05:11 jmacd Exp $
#

DISTNAME=       xdelta-0.23
CATEGORIES=     misc
MASTER_SITES=   ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=	jmacd@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yup
CONFIGURE_ENV= CPPFLAGS="-I${LOCALBASE}/include" \
	LIBS=-L${LOCALBASE}/lib INSTALL_SCRIPT='$${INSTALL} -m 755'

MAN1=           xdelta.1

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
