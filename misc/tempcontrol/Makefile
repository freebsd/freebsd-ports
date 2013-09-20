# Created by: Greg Lehey <grog@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tempcontrol
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	http://www.lemis.com/grog/brewing/src/brewing/tempcontrol/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Temperature control for fermenting beer and other applications

LICENSE=	BSD

MAKE_ARGS=	CFLAGS="${CFLAGS} -Wall -Wno-parentheses"
NO_WRKSUBDIR=	yes

PORTDOCS=	README
PLIST_FILES=	bin/tempcontrol share/tempcontrol/temperaturecontrolrc.sample \
		etc/rc.d/temperaturecontrol.sh.sample
PLIST_DIRS=	share/tempcontrol

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

# Must (re)generate depedencies, otherwise parallel builds would not work
pre-build:
	${MAKE_CMD} -C ${WRKSRC} depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tempcontrol ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/tempcontrol
	${INSTALL_DATA} ${WRKSRC}/temperaturecontrolrc.sample \
		${PREFIX}/share/tempcontrol
	${INSTALL_SCRIPT} ${WRKSRC}/temperaturecontrol.sh.sample \
		${PREFIX}/etc/rc.d
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
