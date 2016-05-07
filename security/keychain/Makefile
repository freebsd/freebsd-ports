# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	keychain
PORTVERSION=	2.8.2
CATEGORIES=	security
MASTER_SITES=	http://www.funtoo.org/archive/keychain/ \
		GENTOO

MAINTAINER=	garga@FreeBSD.org
COMMENT=	User-friendly front-end to ssh-agent(1)

LICENSE=	GPLv2

USES=		tar:bzip2
OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/keychain.1.gz

PORTDOCS=	ChangeLog README.md

.if !exists(${LOCALBASE}/bin/ssh-agent) && !exists(/usr/bin/ssh-agent)
RUN_DEPENDS+=	ssh-agent:security/openssh-portable
.endif

post-patch:
	@${REINPLACE_CMD} -e '1 s,^.*,#!/bin/sh,' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
