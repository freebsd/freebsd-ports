# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	massh
PORTVERSION=	2.0.57
PORTREVISION=	2
CATEGORIES=	security sysutils
MASTER_SITES=	http://m.a.tt/er/
DISTNAME=	massh
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel ssh command execution and file transfer on multiple hosts

BROKEN=		mismatch in distfile checksum

LICENSE=	GPLv3+

RUN_DEPENDS=	bash:shells/bash \
		ambit:shells/ambit

MASSHDIR?=	/var/spool/massh
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	MASSHDIR=${MASSHDIR}

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
	@${MKDIR} ${STAGEDIR}${MASSHDIR}/pull
	@${MKDIR} ${STAGEDIR}${MASSHDIR}/push
	@${MKDIR} ${STAGEDIR}${MASSHDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/massh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/lib/massh/libmassh.sh \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/etc/massh/massh.conf \
		${STAGEDIR}${PREFIX}/etc/massh.conf.sample
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man1/massh.1.gz \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
