# Created by: grog
# $FreeBSD$

PORTNAME=	dirdiff
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	sysutils tcl tk
MASTER_SITES=	https://ftp.samba.org/pub/paulus/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical diff tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		tk
USE_LDCONFIG=	yes

PLIST_FILES=	bin/dirdiff lib/libfilecmp.so.0.0

CFLAGS+=	-fPIC -I${TCL_INCLUDEDIR}

# When bsdmake is used to build the port, the ports infrastructure should call
# it with MAKE_ENV+=  __MAKE_CONF=/dev/null to avoid sourcing make.conf twice.
# This is a workaround to make sure CFLAGS are passed through.
MAKE_ARGS=	CFLAGS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|.0.0|.0|g ; \
		 s|^CFLAGS=|CFLAGS?=|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^exec wish |exec ${WISH} |' ${WRKSRC}/dirdiff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dirdiff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libfilecmp.so.0 ${STAGEDIR}${PREFIX}/lib/libfilecmp.so.0.0

.include <bsd.port.mk>
