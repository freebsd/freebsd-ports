# Created by: ijliao
# $FreeBSD$

PORTNAME=	oinkmaster
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Help you update your snort rules after each update

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	wget:ftp/wget

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	oinkmaster.pl
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/oinkmaster \
		etc/oinkmaster.conf.sample \
		man/man1/oinkmaster.1.gz

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster.pl ${STAGEDIR}${PREFIX}/bin/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/oinkmaster.conf ${STAGEDIR}${PREFIX}/etc/oinkmaster.conf.sample
	${INSTALL_MAN} ${WRKSRC}/oinkmaster.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
