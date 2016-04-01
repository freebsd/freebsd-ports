# Created by: Linh Pham <question+fbsdports@closedsrc.org>
# $FreeBSD$

PORTNAME=	vlogger
PORTVERSION=	1.3
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://n0rp.chemlab.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logging utility for Apache servers with many virtual hosts

BROKEN=		unfetchable

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

USES=		perl5 shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	vlogger

OPTIONS_DEFINE=	EXAMPLES

PLIST_FILES=	bin/vlogger \
		man/man1/vlogger.1.gz
PORTDATA=	mysql_create.sql
PORTEXAMPLES=	vlogger-dbi.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-dbi.conf \
		${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}-dbi.conf
	${INSTALL_DATA} ${WRKSRC}/mysql_create.sql ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
