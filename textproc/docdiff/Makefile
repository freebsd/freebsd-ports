# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docdiff
PORTVERSION=	0.4.0
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compares two text files by word, by character, or by line

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv

PORTDOCS=	readme.html readme.en.html readme.ja.html

post-patch:
	@${REINPLACE_CMD} \
		-e '1 s|#!.*|#!${RUBY}|' \
		-e '/ :format/ s|html|tty|' \
		-e '/SystemConfigFileName =/ s|etc.*conf|${PREFIX}/etc/${PORTNAME}.conf|' \
		-e 's|/etc/docdiff/docdiff.conf|${PREFIX}/etc/${PORTNAME}.conf|' \
			${WRKSRC}/${PORTNAME}.rb

do-install:
	cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.rb ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.example ${STAGEDIR}${PREFIX}/etc
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
