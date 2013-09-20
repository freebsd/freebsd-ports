# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	ambit
PORTVERSION=	2.0.39
CATEGORIES=	shells
MASTER_SITES=	http://m.a.tt/er/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sklauder@trimind.de
COMMENT=	Extended bash brace expansion to expand hostnames or commands

LICENSE=	GPLv3

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

AMBITDIR?=	/var/spool/${PORTNAME}
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	AMBITDIR=${AMBITDIR}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} \
		-e "s!/bin/bash!${LOCALBASE}/bin/bash!" \
		-e "s!/etc/.MyNameIs/!${PREFIX}/etc/!" \
		-e "s!/usr/lib/.MyNameIs/!${PREFIX}/lib/!" \
		-e "s!/var/.MyNameIs!${AMBITDIR}!" ${WRKSRC}/usr/bin/ambit

do-install:
	@${MKDIR} ${AMBITDIR}/hosts
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/ambit ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/lib/ambit/libambit.sh ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man1/${PORTNAME}.1.gz ${MANPREFIX}/man/man1
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
	 ${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf ; \
	fi

.include <bsd.port.mk>
