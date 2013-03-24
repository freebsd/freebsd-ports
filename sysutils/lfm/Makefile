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

MAN1=		lfm.1 pyview.1

post-patch:
	@${REINPLACE_CMD} -e \
		'/DOC_FILES/d ; \
		 /MAN_FILES/d' ${WRKSRC}/setup.py

.include <bsd.port.options.mk>

post-install:
.for f in lfm pyview
	(cd ${WRKSRC} && ${INSTALL_MAN} ${f}.1 ${MAN1PREFIX}/man/man1)
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ChangeLog NEWS README README.pyview TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
