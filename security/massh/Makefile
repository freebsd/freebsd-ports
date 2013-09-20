# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	massh
PORTVERSION=	2.0.57
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	http://m.a.tt/er/
DISTNAME=	massh
EXTRACT_SUFX=	.tgz

MAINTAINER=	sklauder@trimind.de
COMMENT=	Parallel ssh command execution and file transfer on multiple hosts

LICENSE=	GPLv3

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		ambit:${PORTSDIR}/shells/ambit

MASSHDIR?=	/var/spool/massh
MAN1=		massh.1
MANCOMPRESSED=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	MASSHDIR=${MASSHDIR}

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e "s!/bin/bash!${LOCALBASE}/bin/bash!" \
		${WRKSRC}/usr/bin/massh
	@${REINPLACE_CMD} -e 's!/etc/.MyNameIs/!${PREFIX}/etc/!' \
		${WRKSRC}/usr/bin/massh
	@${REINPLACE_CMD} -e "s!/usr/lib/.MyNameIs/!${PREFIX}/lib/!" \
		${WRKSRC}/usr/bin/massh
	@${REINPLACE_CMD} -e "s!/var/.MyNameIs!${MASSHDIR}!" \
		${WRKSRC}/usr/bin/massh
	@${REINPLACE_CMD} -e "s!PATH=/usr/bin:/bin!PATH=/usr/bin:/bin:${LOCALBASE}/bin!" \
		${WRKSRC}/etc/massh/massh.conf
	@${REINPLACE_CMD} -e 's!SyslogMassh="yes"!SyslogMassh="no"!' \
		${WRKSRC}/etc/massh/massh.conf

do-install:
	${MKDIR} ${MASSHDIR}/pull
	${MKDIR} ${MASSHDIR}/push
	${MKDIR} ${MASSHDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/massh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/lib/massh/libmassh.sh ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/etc/massh/massh.conf ${PREFIX}/etc/massh.conf.example
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; \
	then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.example ${PREFIX}/etc/${PORTNAME}.conf; \
	fi
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man1/massh.1.gz ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
