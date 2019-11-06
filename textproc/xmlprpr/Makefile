# Created by: Paul Chvostek <paul+ports@it.ca>
# $FreeBSD$

PORTNAME=	xmlprpr
PORTVERSION=	1.32
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/ \
		http://www.it.ca/~paul/src/
DISTFILES=	xmlpp.pl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML pretty printer

BROKEN=		unfetchable

USES=		shebangfix perl5
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SHEBANG_FILES=	xmlpp.pl

PLIST_FILES=	bin/xmlprpr

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -f ${_DISTDIR}/${_DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlpp.pl ${STAGEDIR}${PREFIX}/bin/xmlprpr

.include <bsd.port.mk>
