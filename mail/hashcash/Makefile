# New ports collection makefile for:	hashcash
# Date created:				Jan 30, 2003
# Whom:					bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	hashcash
PORTVERSION=	1.18
CATEGORIES=	mail
MASTER_SITES=	http://www.hashcash.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bremner@unb.ca
COMMENT=	Anti-spam / denial of service counter-measure tool

MAN1=		hashcash.1 sha1-hashcash.1
PLIST_FILES=	bin/hashcash bin/sha1
PORTDOCS=	CHANGELOG LICENSE README
ALL_TARGET=	generic

.if defined(NOPORTDOCS)

USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e '/DOC_INSTALL_PATH/d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
