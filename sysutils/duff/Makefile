# $FreeBSD$

PORTNAME=	duff
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Duplicate file finder

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase tar:bzip2 shebangfix
GNU_CONFIGURE=	yes
bash_OLD_CMD=	/bin/sh
SHEBANG_FILES=	join-duplicates.sh

PORTDOCS=	README.SHA

OPTIONS_DEFINE=	DOCS JOIN NLS
OPTIONS_SUB=	yes

JOIN_DESC=		Add run-dependencies for join-duplicates.sh
JOIN_RUN_DEPENDS=	bash:shells/bash \
			gtouch:sysutils/coreutils

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
