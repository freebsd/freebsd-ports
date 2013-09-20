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
MAN1=		afio.1
OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	README SCRIPTS

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^CC=.*$$|CC=${CC}|' \
		${WRKSRC}/Makefile

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/SCRIPTS ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/afiodump.example ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/script1/DONTDUMP ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script2/* ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script3/* ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script4/* ${EXAMPLESDIR}
PLIST_SUB+=	PORTEXAMPLES=""
.else
PLIST_SUB+=	PORTEXAMPLES="@comment "
.endif

.include <bsd.port.mk>
