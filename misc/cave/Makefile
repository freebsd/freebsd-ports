# Created by: ijliao
# $FreeBSD$

PORTNAME=	cave
PORTVERSION=	1.0b
CATEGORIES=	misc
MASTER_SITES=	SF/bjk/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character Animation Viewer for Everyone

GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/doc/${PORTNAME}.1

.include <bsd.port.mk>
