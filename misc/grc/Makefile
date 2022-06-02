# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>

PORTNAME=	grc
PORTVERSION=	1.13
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	walter@lifeforms.nl
COMMENT=	Generic Colouriser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:run shebangfix
SHEBANG_FILES=	grc grcat

USE_GITHUB=	yes
GH_ACCOUNT=	garabik

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
.for i in grc grcat
	@${REINPLACE_CMD} -e \
		's|"/etc/grc|"${PREFIX}/etc/grc|g ; \
		 s|/usr/local/share/grc|${DATADIR}|g ; \
		 s|#! /usr/bin/env python3|#!${PYTHON_CMD}| ; \
		 s|, "/usr/share/grc/"||g' ${WRKSRC}/${i}
	@${REINPLACE_CMD} -e \
		's| /etc/grc| ${PREFIX}/etc/grc|g ; \
		 s|/usr/local/share/grc|${DATADIR}|g ; \
		 s|, /usr/share/grc/||g' ${WRKSRC}/${i}.1
.endfor
	(cd ${FILESDIR} && ${CP} colourfiles/conf.* ${WRKSRC}/colourfiles)

do-install:
.for i in grc grcat
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${i}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1)
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} grc.conf ${STAGEDIR}${PREFIX}/etc)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} colourfiles/conf.* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
