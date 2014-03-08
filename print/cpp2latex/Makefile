# Created by: ijliao
# $FreeBSD$

PORTNAME=	cpp2latex
PORTVERSION=	2.3
CATEGORIES=	print
MASTER_SITES=	http://www.arnoldarts.de/files/cpp2latex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts C++ source to output that can be used in LaTeX documents

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README TODO

PLIST_FILES=	bin/cpp2latex

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/-O2 /s|^|#|' -e '/-pedantic /s|^|#|' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
