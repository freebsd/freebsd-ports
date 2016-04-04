# Created by: Ganael LAPLANCHE <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	evtViewer
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/evtViewer/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Ms event log viewer

LICENSE=	GPLv2

NO_ARCH=	yes
USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	evtViewer
NO_BUILD=	yes

PLIST_FILES=	bin/evtViewer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/evtViewer ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
