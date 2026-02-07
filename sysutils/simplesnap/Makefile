PORTNAME=	simplesnap
PORTVERSION=	2.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Transfers ZFS snapshots across a network
WWW=		https://github.com/jgoerzen/simplesnap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		gdate:sysutils/coreutils \
		pv:sysutils/pv

USES=		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	jgoerzen
GH_TAGNAME=	1704a6c534

PLIST_FILES=	sbin/${PORTNAME} \
		sbin/${PORTNAME}wrap \
		share/man/man8/simplesnap.8.gz
SHEBANG_FILES=	${PORTNAME} ${PORTNAME}wrap

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}wrap ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
