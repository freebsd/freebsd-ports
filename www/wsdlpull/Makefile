# ex:ts=8
# Ports collection makefile for:	wsdlpull
# Date created:			Mar 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wsdlpull
PORTVERSION=	1.9.8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ WSDL Parser

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/${DISTNAME:R}

USE_GNOME=	gnometarget
USE_GCC=	3.4+
USE_GETOPT_LONG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/wsdl
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|: install-docsDATA|:|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/wsdlpull.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
