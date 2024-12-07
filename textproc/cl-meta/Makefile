PORTNAME=	meta
PORTVERSION=	0.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	textproc lisp
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Parser generator for Common Lisp
WWW=		http://home.pipeline.com/~hbaker1/Prag-Parse.html

BROKEN=		Unfetchable
DEPRECATED=	Upstream is gone
EXPIRATION_DATE=2024-12-31

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USES=		cl

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/meta.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/meta.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Prag-Parse.* ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
