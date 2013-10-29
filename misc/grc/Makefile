# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grc
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://kassiopeia.juls.savba.sk/~garabik/software/grc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Colouriser

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

USES=		shebangfix
SHEBANG_FILES=	grc grcat
USE_PYTHON_RUN=	yes

post-patch:
.for i in grc grcat
	@${REINPLACE_CMD} -e \
		's|"/etc/grc|"${PREFIX}/etc/grc|g ; \
		 s|/usr/local/share/grc|${DATADIR}|g ; \
		 s|, "/usr/share/grc/"||g' ${WRKSRC}/${i}
	@${REINPLACE_CMD} -e \
		's| /etc/grc| ${PREFIX}/etc/grc|g ; \
		 s|/usr/local/share/grc|${DATADIR}|g ; \
		 s|, /usr/share/grc/||g' ${WRKSRC}/${i}.1
.endfor

do-install:
.for i in grc grcat
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${i}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1)
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} grc.conf ${STAGEDIR}${PREFIX}/etc)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} conf.* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
