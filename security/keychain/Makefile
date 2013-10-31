# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	keychain
PORTVERSION=	2.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.funtoo.org/archive/keychain/ \
		GENTOO/distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	User-friendly front-end to ssh-agent(1)

LICENSE=	GPLv2

USES=		gmake perl5
USE_PERL5=	build
OPTIONS_DEFINE=	DOCS
FETCH_ARGS?=	-Fpr
USE_BZIP2=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/keychain.1.gz

PORTDOCS=	ChangeLog README.rst

.if !exists(${LOCALBASE}/bin/ssh-agent) && !exists(/usr/bin/ssh-agent)
RUN_DEPENDS+=	ssh-agent:${PORTSDIR}/security/openssh-portable
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
