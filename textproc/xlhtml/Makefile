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

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake tar:tgz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
.for dir in xlhtml ppthtml
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${dir}
	cd ${WRKSRC}/${dir} && \
		${INSTALL_DATA} ChangeLog README THANKS \
		${STAGEDIR}${DOCSDIR}/${dir}
.endfor

.include <bsd.port.mk>
