# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$
PORTNAME=	44bsd-csh
PORTVERSION=	20001106
PORTREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The traditional 4.4BSD /bin/csh C-shell

USE_BZIP2=	yes

BUILD_DEPENDS=	rcs:${PORTSDIR}/devel/rcs57

NO_WRKSUBDIR=	yes
PORTDOCS=	paper.ascii.gz

post-extract:
	cd ${WRKSRC} ; co RCS/*,v; chmod u+w *
	cd ${WRKSRC}/USD.doc ; co RCS/*,v

post-build:
	cd ${WRKSRC}/USD.doc ; ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csh ${STAGEDIR}${PREFIX}/bin/44bsd-csh
	${INSTALL_MAN} ${WRKSRC}/csh.1 ${STAGEDIR}${PREFIX}/man/man1/44bsd-csh.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/USD.doc/paper.ascii.gz ${STAGEDIR}${DOCSDIR}

tarup:
	cd ${WRKSRC} ; rm * USD.doc/*
	cd ${WRKSRC} ; ${TAR} cvyf /tmp/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

.include <bsd.port.mk>
