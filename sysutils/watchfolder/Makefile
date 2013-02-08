# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	watchfolder
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Watch folders for new files and process them

LICENSE=	GPLv2

MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/watchd-${PORTVERSION}
USE_RC_SUBR=	watchd

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|gcc $$(OPT)|${CC} ${CFLAGS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/README ${WRKSRC}/watchd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/watchd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/watchd.conf ${PREFIX}/etc/watchd.conf.sample
	[ -f ${PREFIX}/etc/watchd.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/watchd.conf ${PREFIX}/etc
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/watchfolder.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
