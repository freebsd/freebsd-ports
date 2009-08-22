# Ports collection makefile for:  pixilate
# Date created:			  Wed Apr 30 06:10:16 PDT 2003
# Whom:				  Barry Irwin <bvi@moria.org>
#
# $FreeBSD$

PORTNAME=	pixilate
PORTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/winfingerprint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates packets to match a list of Cisco PIX access lists

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/pixilate

USE_AUTOTOOLS=	automake:15 autoconf:262
AUTOMAKE_ARGS=	--add-missing

#CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${LIBS}" CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		pixilate.1

PORTDOCS=	README
PLIST_FILES=	bin/pixilate

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|; \
		 s|--defines`|& `${LIBNET_CONFIG} --cflags`|' \
		${WRKSRC}/configure.ac

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
