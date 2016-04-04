# Created by: Juraj Lutter <otis@sk.FreeBSD.org>
# $FreeBSD$

PORTNAME=	tartarus
PORTVERSION=	0.9.8
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://wertarbyte.de/tartarus/ \
		http://ftp.wilbury.sk/pub/FreeBSD/local/distfiles/

MAINTAINER=	otis@sk.FreeBSD.org
COMMENT=	Wrappers around common Unix tools for simplified backup solution

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/gtar:archivers/gtar \
		${LOCALBASE}/bin/curl:ftp/curl

USES=		gmake perl5 shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/bin/*

do-install:
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} charon charon.ftp charon.local \
		charon.pipe orpheus tartarus ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} Tartarus ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	cd ${WRKSRC}/man && ${INSTALL_MAN} charon.ftp.1 charon.local.1 \
		charon.pipe.1 tartarus.1 ${STAGEDIR}${PREFIX}/man/man1
	${LN} -sf charon.ftp.1 ${STAGEDIR}${PREFIX}/man/man1/charon.1

.include <bsd.port.mk>
