# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	debootstrap
PORTVERSION=	1.0.123
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN/pool/main/d/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Install Debian or Ubuntu base system into a directory

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/debian/copyright

RUN_DEPENDS=	wget:ftp/wget \
		bash:shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
USES=		gmake perl5
USE_PERL5=	run

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/debootstrap

post-install:
	${INSTALL_MAN} ${WRKSRC}/debootstrap.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8/debootstrap.8

.include <bsd.port.mk>
