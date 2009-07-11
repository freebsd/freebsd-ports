# New ports collection makefile for:	nipper
# Date created:		3 May 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nipper
PORTVERSION=	0.12.6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netdev config analyzer

PLIST_FILES=	bin/${PORTNAME} etc/nipper.conf.sample
PORTDOCS=	Changelog Readme TODO Features.txt Options.txt Quickstart.txt \
		XML.txt
MAN1=	${PORTNAME}.1
MAN5=	${PORTNAME}.conf.5

post-extract:
	@${MV} ${WRKSRC}/docs/* ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|'\
		${WRKSRC}/common/* ${WRKSRC}/man/*

do-build:
	@cd ${WRKSRC}/ && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/nipper.conf ${PREFIX}/etc/nipper.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/man/nipper.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/man/nipper.conf.5 ${MAN5PREFIX}/man/man5/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
