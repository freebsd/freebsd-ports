# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t-prot
PORTVERSION=	2.101
CATEGORIES=	mail
MASTER_SITES=	http://www.escape.de/~tolot/mutt/t-prot/downloads/ \
		LOCAL/sergei

MAINTAINER=	torres.g.alex@gmail.com
COMMENT=	TOFU Protection - Display Filter for RFC822 messages

RUN_DEPENDS=	p5-Getopt-Long>=0:devel/p5-Getopt-Long \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext

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
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
