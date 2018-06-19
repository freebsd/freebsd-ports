# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlhtml
PORTVERSION=	0.5
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/chicago/${PORTNAME}/backend

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Excel and PowerPoint files to HTML and text

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake tar:tgz

# If autotools are installed in the build environment a regeneration
# of it's build files is triggered for unknown reasons.  Pretend they
# are not there.
BINARY_ALIAS=	aclocal=false autoheader=false automake=false makeinfo=false

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
.for dir in xlhtml ppthtml
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${dir}
	cd ${WRKSRC}/${dir} && \
		${INSTALL_DATA} ChangeLog README THANKS \
		${STAGEDIR}${DOCSDIR}/${dir}
.endfor

post-build:
	@${STRIP_CMD} ${WRKSRC}/xlhtml/xlhtml
	@${STRIP_CMD} ${WRKSRC}/ppthtml/ppthtml

.include <bsd.port.mk>
