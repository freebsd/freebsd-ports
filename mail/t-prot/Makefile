# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t-prot
PORTVERSION=	3.4
CATEGORIES=	mail
MASTER_SITES=	http://www.escape.de/~tolot/mutt/t-prot/downloads/

MAINTAINER=	torres.g.alex@gmail.com
COMMENT=	TOFU Protection - Display Filter for RFC822 messages

LICENSE=	BSD4CLAUSE

RUN_DEPENDS=	p5-Locale-gettext>=0:devel/p5-Locale-gettext

NO_ARCH=	yes
USES=		perl5 shebangfix
NO_BUILD=	yes

PORTDOCS=	ChangeLog README TODO
PORTEXAMPLES=	*
PLIST_FILES=	man/man1/t-prot.1.gz bin/t-prot
SHEBANG_FILES=	t-prot

OPTIONS_DEFINE=	EXAMPLES DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/t-prot ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/t-prot.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
