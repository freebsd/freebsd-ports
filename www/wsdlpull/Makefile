# ex:ts=8
# Ports collection makefile for:	wsdlpull
# Date created:			Mar 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wsdlpull
PORTVERSION=	1.23
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	C++ WSDL Parser

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

MAKE_JOBS_SAFE=  yes

USE_GNOME=	gnometarget
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/wsdl
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|: install-docsDATA|:|g'
	@${REINPLACE_CMD} -e '/-O2 -Wall/d' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/wsdlpull.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
