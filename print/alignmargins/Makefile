# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alignmargins
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.linuxprinting.org/download/printing/
MASTER_SITE_SUBDIR=lofi
DISTFILES=	alignmargins align.ps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility script to generate custom margins in PPDs for CUPS

NO_BUILD=	yes
USES=		perl5

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			-e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/alignmargins

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/align.ps ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
