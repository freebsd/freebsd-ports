# Created by: Alex Kapranoff <kapr@crosswinds.net>
# $FreeBSD$

PORTNAME=	xslint
PORTVERSION=	005
CATEGORIES=	textproc perl5
MASTER_SITES=	http://nwalsh.com/obsolete/xslint/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL(T) stylesheet checker

RUN_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM

USES=		shebangfix perl5 zip
USE_PERL5=	run

WRKSRC=		${WRKDIR}/${PORTNAME}-0.05
NO_BUILD=	yes

SHEBANG_FILES=	xslint.pl

PLIST_FILES=	bin/xslint
PORTDOCS=	README xslint.html xslint.xml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
