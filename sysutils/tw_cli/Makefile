# Created by: Dmitry Frolov <frolov@riss-telecom.ru>
# $FreeBSD$

PORTNAME=	tw_cli
PORTVERSION=	9.5.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://tsupport:tsupport@ftp0.lsil.com/private/3Ware/downloads/
DISTNAME=	cli_freebsd_10.2.1_9.5.4

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	3ware storage controllers management CLI

EXTRACT_SUFX:=	.zip

RESTRICTED=	Redistribution is not allowed
# i386 binary should work on ia64, but not tested
ONLY_FOR_ARCHS=	i386 amd64 ia64

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
BINSUFFIX=	${ARCH:S,i386,x86,:S,amd64,x86_64,:S,ia64,x86,}
SUB_FILES=	407.status-3ware-raid
PORTDOCS=	tw_cli.8.html

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BINSUFFIX}/tw_cli\
		${STAGEDIR}/${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/tw_cli.8.nroff\
		${STAGEDIR}/${MANPREFIX}/man/man8/tw_cli.8
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/407.status-3ware-raid \
		${STAGEDIR}/${PREFIX}/etc/periodic/daily/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tw_cli.8.html ${STAGEDIR}/${DOCSDIR}/
.endif

.include <bsd.port.mk>
