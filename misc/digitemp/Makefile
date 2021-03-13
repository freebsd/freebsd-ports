# Created by: Evaldas Auryla <ea@zaib.as>
# $FreeBSD$

PORTNAME=	digitemp
PORTVERSION=	3.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dallas Semiconductor 1-wire device reading console application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	bcl

ALL_TARGET=	ds9097 ds9097u

PLIST_FILES=	bin/digitemp_DS9097 bin/digitemp_DS9097U \
		etc/digitemp.conf.sample \
		man/man1/digitemp.1.gz

DOCS=		ChangeLog CREDITS FAQ README TODO dthowto.txt \
		DS9097_Schematic.gif perl python/mysql rrdb
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-install:
	@${REINPLACE_CMD} -e "s/dev\/ttyS/dev\/cuau/g" ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digitemp_DS9097 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/digitemp_DS9097U ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${FILESDIR}/digitemp.conf.sample ${STAGEDIR}${PREFIX}/etc/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Sample config installed at ${PREFIX}/etc/digitemp.conf.sample"
	@${ECHO_MSG} ""

do-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
