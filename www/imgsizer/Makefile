# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	imgsizer
PORTVERSION=	2.8
CATEGORIES=	www textproc
MASTER_SITES=	http://www.catb.org/~esr/imgsizer/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Tool to autogenerate WIDTH and HEIGHT for IMG HTML tags

LICENSE=	BSD

RUN_DEPENDS=	rdjpgcom:${PORTSDIR}/graphics/jpeg \
		identify:${PORTSDIR}/graphics/ImageMagick

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/imgsizer.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/imgsizer

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/imgsizer.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
