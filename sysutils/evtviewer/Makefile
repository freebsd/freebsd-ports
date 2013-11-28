# Created by: Ganael LAPLANCHE <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	evtViewer
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/evtViewer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Ms event log viewer

LICENSE=	GPLv2

USES=		perl5 shebangfix
SHEBANG_FILES=	evtViewer
NO_BUILD=	yes

PLIST_FILES=	bin/evtViewer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/evtViewer ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
