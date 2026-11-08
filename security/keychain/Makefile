PORTNAME=	keychain
PORTVERSION=	2.9.8
CATEGORIES=	security

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	User-friendly front-end to ssh-agent(1)
WWW=		https://kernel-seeds.org/projects/keychain/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

.if !exists(${LOCALBASE}/bin/ssh-agent) && !exists(/usr/bin/ssh-agent)
RUN_DEPENDS+=	ssh-agent:security/openssh-portable
.endif

USES=		perl5

USE_GITHUB=	yes
GH_ACCOUNT=	danielrobbins
USE_PERL5=	build

CONFLICTS_INSTALL=	py*-pycoin # bin/keychain

PLIST_FILES=	bin/keychain \
		share/man/man1/keychain.1.gz
PORTDOCS=	ChangeLog.md README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${STAGEDIR}${PREFIX}/share/man/man1

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
