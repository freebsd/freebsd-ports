# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	ambit
PORTVERSION=	2.0.39
CATEGORIES=	shells
MASTER_SITES=	http://m.a.tt/er/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended bash brace expansion to expand hostnames or commands

LICENSE=	GPLv3+

RUN_DEPENDS=	bash:shells/bash

USES=		tar:tgz
AMBITDIR?=	/var/spool/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BROKEN=		checksum mismatch

PLIST_SUB=	AMBITDIR=${AMBITDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s!/bin/bash!${LOCALBASE}/bin/bash!" \
		-e "s!/etc/.MyNameIs/!${PREFIX}/etc/!" \
		-e "s!/usr/lib/.MyNameIs/!${PREFIX}/lib/!" \
		-e "s!/var/.MyNameIs!${AMBITDIR}!" ${WRKSRC}/usr/bin/ambit

do-install:
	@${MKDIR} ${STAGEDIR}${AMBITDIR}/hosts
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/ambit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/lib/ambit/libambit.sh ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man1/${PORTNAME}.1.gz ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
