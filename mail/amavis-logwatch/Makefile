# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	amavis-logwatch
PORTVERSION=	1.51.02
CATEGORIES=	mail
MASTER_SITES=	SF/logreporters/${PORTNAME}/release/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Amavisd-new log parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	Bugs Changes README
PORTEXAMPLES=	${PORTNAME}.conf

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
SHEBANG_FILES=	amavis-logwatch
OPTIONS_DEFINE=	EXAMPLES DOCS
OPTIONS_DEFAULT=EXAMPLES DOCS

.include <bsd.port.options.mk>

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
