# Created by: Juergen Lock <nox@jelal.hb.north.de>
# $FreeBSD$

PORTNAME=	afio
PORTVERSION=	2.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/backup
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archiver & backup program w/ builtin compression

ALL_TARGET=	${PORTNAME}
OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|^CC=.*$$|CC=${CC}|' \
		${WRKSRC}/Makefile

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/SCRIPTS ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/afiodump.example ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/script1/DONTDUMP ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script2/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script3/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script4/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
