# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	anyremote2html
PORTVERSION=	1.4
CATEGORIES=	www deskutils
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web interface for anyRemote

RUN_DEPENDS=	anyremote:comms/anyremote

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		python:run

PORTDOCS=	ChangeLog README COPYING AUTHORS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
