# ex:ts=8
# Ports collection makefile for:	libparsifal
# Date created:			Jan 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libparsifal
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight XML Parser

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|g' ${WRKSRC}/configure

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for D in "" csrchtml pics
	@${MKDIR} ${DOCSDIR}/${D}
	${INSTALL_DATA} ${WRKSRC}/doc/${D}/*.* ${DOCSDIR}/${D}
.endfor
.endif

.include <bsd.port.mk>
