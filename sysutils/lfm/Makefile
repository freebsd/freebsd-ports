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

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=	ChangeLog NEWS README README.pyview TODO

post-patch:
	@${REINPLACE_CMD} -e \
		'/DOC_FILES/d ; \
		 /MAN_FILES/d' ${WRKSRC}/setup.py

.include <bsd.port.options.mk>

post-install:
.for f in lfm pyview
	(cd ${WRKSRC} && ${INSTALL_MAN} ${f}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1)
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
