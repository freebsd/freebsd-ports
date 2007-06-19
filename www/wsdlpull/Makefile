# ex:ts=8
# Ports collection makefile for:	wsdlpull
# Date created:			Mar 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wsdlpull
PORTVERSION=	1.13
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ WSDL Parser

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl

USE_GNOME=	gnometarget
USE_GCC=	3.4+
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/wsdl
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|: install-docsDATA|:|g'
	@${REINPLACE_CMD} -e '/-O2 -Wall/d' \
	    -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/wsdlpull.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
