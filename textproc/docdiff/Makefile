# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docdiff
PORTVERSION=	0.4.0
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compares two text files by word, by character, or by line

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USE_RUBY=	yes
USES=		shebangfix

PORTDOCS=	readme.html readme.en.html readme.ja.html

SHEBANG_FILES=	${PORTNAME}.rb

post-patch:
	@${REINPLACE_CMD} -e '/ :format/ s|html|tty|' \
		-e '/SystemConfigFileName =/ s|etc.*conf|${PREFIX}/etc/${PORTNAME}.conf|' \
		-e 's|/etc/${PORTNAME}/${PORTNAME}.conf|${PREFIX}/etc/${PORTNAME}.conf|' \
			${WRKSRC}/${PORTNAME}.rb

do-install:
	cd ${WRKSRC}/${PORTNAME}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.rb ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.example ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
