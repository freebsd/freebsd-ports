# Created by: Henrik Andersen
# $FreeBSD$

PORTNAME=	bontmia
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://kosmos.ttyv0.se/attachments/download/37/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small tool for incremental backups over network

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USES=		perl5
USE_PERL5=	run

NO_BUILD=	yes

PLIST_FILES=	bin/bontmia

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bontmia ${PREFIX}/bin

.include <bsd.port.mk>
