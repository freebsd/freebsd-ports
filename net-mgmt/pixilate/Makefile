# Created by: Barry Irwin <bvi@moria.org>
# $FreeBSD$

PORTNAME=	pixilate
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/winfingerprint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates packets to match a list of Cisco PIX access lists

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/pixilate

USES=		libtool
USE_AUTOTOOLS=	aclocal autoconf automake
AUTOMAKE_ARGS=	--add-missing

PORTDOCS=	README
PLIST_FILES=	bin/pixilate man/man1/pixilate.1.gz

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|; \
		 s|--defines`|& `${LIBNET_CONFIG} --cflags`|' \
		${WRKSRC}/configure.ac

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
