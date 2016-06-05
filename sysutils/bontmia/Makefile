# Created by: Henrik Andersen
# $FreeBSD$

PORTNAME=	bontmia
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://kosmos.ttyv0.se/attachments/download/37/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small tool for incremental backups over network

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	rsync:net/rsync

USES=		perl5
USE_PERL5=	run

NO_BUILD=	yes

PLIST_FILES=	bin/bontmia

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bontmia ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
