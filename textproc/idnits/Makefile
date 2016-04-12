# Created by: fenner@FreeBSD.org
# $FreeBSD$

PORTNAME=	idnits
PORTVERSION=	2.14.01
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/idnits/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Looks for problems in internet draft formatting

LICENSE=	GPLv2+

RUN_DEPENDS=	bash:shells/bash

NO_ARCH=	yes
NO_BUILD=	yes
USES=		shebangfix tar:tgz

PLIST_FILES=	bin/${PORTNAME}

SHEBANG_FILES=	${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
