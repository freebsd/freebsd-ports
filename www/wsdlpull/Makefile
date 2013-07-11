# ex:ts=8
# Ports collection makefile for:	wsdlpull
# Date created:			Mar 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wsdlpull
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ WSDL Parser

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

MAN1=		wsdlpull.1 wsdlpull-schema.1

post-patch:
	@${REINPLACE_CMD} -e '/-O2 -Wall/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e '/SUBDIRS = / s| docs||' \
		-e '/^install-data-am:/ s| install-docsDATA||' \
			${WRKSRC}/Makefile.in
# Do not install wsdlpull-config.1 for the absence of wsdlpull-config
	@${REINPLACE_CMD} \
		-e '/^man_MANS = / s| wsdlpull-config.1||' \
			${WRKSRC}/man/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} README wsdlpull.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
