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

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	oinkmaster.pl

PLIST_FILES=	bin/oinkmaster \
		etc/oinkmaster.conf.sample \
		man/man1/oinkmaster.1.gz

PORTDOCS=	README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster.pl ${STAGEDIR}${PREFIX}/bin/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/oinkmaster.conf ${STAGEDIR}${PREFIX}/etc/oinkmaster.conf.sample
	${INSTALL_MAN} ${WRKSRC}/oinkmaster.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
