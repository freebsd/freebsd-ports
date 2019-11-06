# Created by: Philip Jenvey <pjenvey@groovie.org>
# $FreeBSD$

PORTNAME=	hellanzb
PORTVERSION=	0.13
PORTREVISION=	4
CATEGORIES=	news
MASTER_SITES=	http://www.hellanzb.com/distfiles/

MAINTAINER=	pjenvey@groovie.org
COMMENT=	Nzb downloader and post processor

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	par2:archivers/par2cmdline \
		flac:audio/flac \
		shorten:audio/shorten \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yenc>=0:news/py-yenc@${PY_FLAVOR} \
		mac:audio/mac

USE_PYTHON=	distutils
USES=		python:2.7
PORTDOCS=	CHANGELOG CREDITS README
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# more fully-featured rar needs i386
.if ${ARCH} == "i386"
RUN_DEPENDS+=	rar:archivers/rar
.else
RUN_DEPENDS+=	unrar:archivers/unrar
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
