# ex:ts=8
# Ports collection makefile for:	xmlindent
# Date created:			Apr 1, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlindent
PORTVERSION=	0.2.17
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	david@dyn-ns.net
COMMENT=	XML stream reformatter

USE_REINPLACE=	yes
MAN1=		xmlindent.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/xmlindent

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/share/man/|/man/|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
