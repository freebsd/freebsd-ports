# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	amavis-logwatch
PORTVERSION=	1.51.03
CATEGORIES=	mail
MASTER_SITES=	SF/logreporters/${PORTNAME}/release/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Amavisd-new log parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	Bugs Changes README
PORTEXAMPLES=	${PORTNAME}.conf

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	run
NO_BUILD=	yes
SHEBANG_FILES=	amavis-logwatch
OPTIONS_DEFINE=	EXAMPLES DOCS

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e '\
		s!/usr/local/etc!${ETCDIR}! \
		' ${PORTNAME} ${PORTNAME}.1 README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${CP} ${WRKSRC}/${PORTNAME}.conf ${WRKSRC}/${PORTNAME}.conf.sample
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${ETCDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
