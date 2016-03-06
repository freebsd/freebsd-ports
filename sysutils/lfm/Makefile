# Created by: ijliao
# $FreeBSD$

PORTNAME=	lfm
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE \
		https://inigo.katxi.org/devel/lfm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Last File Manager, a simple 'commander'-type file manager

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils
NO_ARCH=	yes

PORTDOCS=	ChangeLog NEWS README README.pyview TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/DOC_FILES/d ; \
		 /MAN_FILES/d' ${WRKSRC}/setup.py

post-install:
.for f in lfm pyview
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
