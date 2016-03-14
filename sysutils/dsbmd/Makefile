Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbmd
PORTVERSION=	0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Media mounting daemon

LICENSE=	BSD2CLAUSE

USES=		tar:tgz

USE_RC_SUBR=	dsbmd

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	libexec/dsbmd "@sample etc/dsbmd.conf.sample etc/dsbmd.conf"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README
.endif

.include <bsd.port.mk>
