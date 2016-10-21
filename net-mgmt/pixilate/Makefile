# Created by: Barry Irwin <bvi@moria.org>
# $FreeBSD$

PORTNAME=	pixilate
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/winfingerprint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates packets to match a list of Cisco PIX access lists

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnet.so:net/libnet

WRKSRC=		${WRKDIR}/pixilate

USES=		autoreconf libtool
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/pixilate man/man1/pixilate.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC} && ${RM} INSTALL install-sh missing mkinstalldirs

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
