PORTNAME=	xlhtml
PORTVERSION=	0.5
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/chicago/${PORTNAME}/backend

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Excel and PowerPoint files to HTML and text
WWW=		https://chicago.sourceforge.net/xlhtml/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake tar:tgz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=	DOCS

post-build:
	@${STRIP_CMD} ${WRKSRC}/xlhtml/xlhtml
	@${STRIP_CMD} ${WRKSRC}/ppthtml/ppthtml

post-install-DOCS-on:
.for dir in xlhtml ppthtml
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${dir}
	cd ${WRKSRC}/${dir} && \
		${INSTALL_DATA} ChangeLog README THANKS \
		${STAGEDIR}${DOCSDIR}/${dir}
.endfor

.include <bsd.port.mk>
