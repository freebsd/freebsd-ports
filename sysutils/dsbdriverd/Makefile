# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbdriverd
PORTVERSION=	0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Hardware detecting, device driver loading daemon

LICENSE=	BSD2CLAUSE

USES=		tar:tgz

MAKE_ARGS+=	DBDIR=${DATADIR}

PORTDATA=	drivers.db

USE_RC_SUBR=	dsbdriverd

PLIST_FILES=	libexec/dsbdriverd man/man8/dsbdriverd.8.gz

.include <bsd.port.mk>
