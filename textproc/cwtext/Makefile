# Created by: ijliao
# $FreeBSD$

PORTNAME=	cwtext
PORTVERSION=	0.96
CATEGORIES=	textproc hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Morse Code Generator

USE_PYTHON=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	ALL

LICENSE=	GPLv2

post-patch:
	@${REINPLACE_CMD} -e "s,%%STAGEDIR%%,${STAGEDIR},g" \
		${WRKSRC}/makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
