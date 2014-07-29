# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlhtml
PORTVERSION=	0.5
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/chicago/${PORTNAME}/backend

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Excel and PowerPoint files to HTML and text

LICENSE=	GPLv2

USES=		gmake tar:tgz

USE_AUTOTOOLS=	automake14 autoconf

OPTIONS_DEFINE=	DOCS

post-install:
.for dir in xlhtml ppthtml
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${dir}
	cd ${WRKSRC}/${dir} && \
		${INSTALL_DATA} ChangeLog README THANKS \
		${STAGEDIR}${DOCSDIR}/${dir}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xlhtml \
		${STAGEDIR}${PREFIX}/bin/ppthtml

.include <bsd.port.mk>
