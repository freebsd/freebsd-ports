# New ports collection makefile for:	tclsasl
# Date created:				Wed Apr 26 12:42:16 MSD 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	tclsasl
PORTVERSION=	1.0
CATEGORIES=	security tcl
MASTER_SITES=	http://beepcore-tcl.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsh@vlink.ru
COMMENT=	A Tcl interface to the Cyrus SASLv2 library

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_TCL=	yes
USE_TCL_BUILD=	yes

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-cyrus-sasl=${LOCALBASE}
CONFIGURE_ENV=	INSTALL="${INSTALL_DATA}"

PORTDOCS=	tclsasl.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tclsasl.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
