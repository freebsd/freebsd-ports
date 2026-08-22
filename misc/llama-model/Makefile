PORTNAME=	llama-model
DISTVERSION=	0.3.0
CATEGORIES=	misc

MAINTAINER=	dennis.r.friedrichsen@gmail.com
COMMENT=	Manage and run local GGUF models with llama-server
WWW=		https://github.com/dennisfriedrichsen/llama-model

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	llama-server:misc/llama-cpp

USE_GITHUB=	yes
GH_ACCOUNT=	dennisfriedrichsen

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/llama-model \
		share/man/man1/llama-model.1.gz

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

PORTDOCS=	README.md
PORTEXAMPLES=	llama-models.conf server.args

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|^VERSION=dev$$|VERSION=${DISTVERSION}|' \
		${WRKSRC}/llama-model

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/llama-model ${STAGEDIR}${PREFIX}/bin/llama-model
	${INSTALL_MAN} ${WRKSRC}/llama-model.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/llama-model.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/llama-models.conf.example \
		${STAGEDIR}${EXAMPLESDIR}/llama-models.conf
	${INSTALL_DATA} ${WRKSRC}/server.args.example \
		${STAGEDIR}${EXAMPLESDIR}/server.args
.endif

.include <bsd.port.mk>
