# ex:ts=8
# Ports collection makefile for:	libparsifal
# Date created:			Jan 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libparsifal
PORTVERSION=	0.9.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight XML Parser

USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's| -O3||g' ${WRKSRC}/src/Makefile.in

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for D in "" csrchtml pics
	@${MKDIR} ${DOCSDIR}/${D}
	${INSTALL_DATA} ${WRKSRC}/doc/${D}/*.* ${DOCSDIR}/${D}
.endfor
.endif

.include <bsd.port.mk>
