# Ports collection makefile for:  rats
# Date created:			  22 August 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rats
PORTVERSION=	2.1
CATEGORIES=	security devel
MASTER_SITES=	http://www.securesoftware.com/rats/

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-expat-lib=${LOCALBASE}/lib \
		--with-expat-include=${LOCALBASE}/include/xml

ALL_TARGET=	rats

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/rats
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rats
.endif
MAN1=		rats.1

.include <bsd.port.mk>
