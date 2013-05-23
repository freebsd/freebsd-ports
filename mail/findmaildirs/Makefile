# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	findmaildirs
PORTVERSION=	0.1
CATEGORIES=	mail
MASTER_SITES=	http://cloud.github.com/downloads/AMDmi3/findmaildirs/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple utility to create list of maildirs for mutt

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
