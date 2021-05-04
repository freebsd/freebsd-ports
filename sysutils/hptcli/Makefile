# Created by: William Grzybowski <wg@FreeBSD.org>

PORTNAME=	hptcli
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.highpoint-tech.com/BIOS_Driver/HRM/FreeBSD/
DISTNAME=	CLI-FreeBSD-3.6-1-120913

MAINTAINER=	wg@FreeBSD.org
COMMENT=	HighPoint storage controllers management CLI

# Converted from RESTRICTED
LICENSE=	hptcli
LICENSE_NAME=	hptcli
LICENSE_TEXT=	Redistribution is not allowed
LICENSE_PERMS=	auto-accept

EXTRACT_SUFX=	.tgz

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-extract:
	cd ${WRKSRC} && ${TAR} -xf hptraidconf-3.6-1.tbz && \
		${TAR} -xf hptsvr-3.6-1.tbz

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_MAN} ${WRKSRC}/hptraidconf.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${ARCH} == "i386"
	${INSTALL_PROGRAM} ${WRKSRC}/hptraidconf-8.0 ${STAGEDIR}${PREFIX}/bin/hptraidconf
	${INSTALL_PROGRAM} ${WRKSRC}/hptsvr-3.6/hptsvr-8.0 ${STAGEDIR}${PREFIX}/sbin/hptsvr
.else
	${INSTALL_PROGRAM} ${WRKSRC}/hptraidconf-8.0.amd64 ${STAGEDIR}${PREFIX}/bin/hptraidconf
	${INSTALL_PROGRAM} ${WRKSRC}/hptsvr-3.6/hptsvr-8.0.amd64 ${STAGEDIR}${PREFIX}/sbin/hptsvr
.endif

.include <bsd.port.post.mk>
