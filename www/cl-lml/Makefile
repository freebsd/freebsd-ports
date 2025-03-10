PORTNAME=	lml
PORTVERSION=	2.5.7
PORTREVISION=	3
CATEGORIES=	www textproc
MASTER_SITES=	http://files.b9.com/lml/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Lisp Markup Language
WWW=		http://lml.b9.com/

LICENSE=	GPLv2

USES=		cl

NO_BUILD=	yes

PORTDOCS=	Makefile make.lisp readme.html readme.lml

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${RLN} ${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
