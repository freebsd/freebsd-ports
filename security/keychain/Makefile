# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	keychain
PORTVERSION=	2.8.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.funtoo.org/archive/keychain/ \
		GENTOO

MAINTAINER=	garga@FreeBSD.org
COMMENT=	User-friendly front-end to ssh-agent(1)

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USES=		tar:bzip2 shebangfix
OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes

bash_OLD_CMD=	/bin/sh
SHEBANG_FILES=	${WRKSRC}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/keychain.1.gz

PORTDOCS=	ChangeLog README.md

.if !exists(${LOCALBASE}/bin/ssh-agent) && !exists(/usr/bin/ssh-agent)
RUN_DEPENDS+=	ssh-agent:${PORTSDIR}/security/openssh-portable
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
