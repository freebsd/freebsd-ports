# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bibelot
PORTVERSION=	0.9.4
CATEGORIES=	palm
MASTER_SITES=	SF/${PORTNAME}/Bibelot/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Formats and converts text documents into compressed PalmDoc .pdb files

PLIST_FILES=	bin/bibelot
USES=		perl5

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
