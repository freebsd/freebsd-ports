# Created by: Paul Chvostek <paul+ports@it.ca>
# $FreeBSD$

PORTNAME=	xmldiff
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/ \
		http://www.it.ca/~paul/src/
DISTFILES=	xmldiff.pl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display meaningful differences between XML files

RUN_DEPENDS=	xmlprpr:textproc/xmlprpr

USES=		shebangfix perl5
NO_BUILD=	yes

SHEBANG_FILES=	xmldiff.pl

PLIST_FILES=	bin/xmldiff

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -f ${_DISTDIR}/${_DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmldiff.pl ${STAGEDIR}${PREFIX}/bin/xmldiff

.include <bsd.port.mk>
