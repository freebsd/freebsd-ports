# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	tclsasl
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	security tcl
MASTER_SITES=	http://beepcore-tcl.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsh@vlink.ru
COMMENT=	Tcl interface to the Cyrus SASLv2 library

LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

USES=		tcl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-cyrus-sasl=${LOCALBASE} \
		--prefix=${PREFIX}
CONFIGURE_ENV=	INSTALL="${INSTALL_DATA}" STAGEDIR="${STAGEDIR}"

PORTDOCS=	tclsasl.html

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tclsasl.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
