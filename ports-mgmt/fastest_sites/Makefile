# $FreeBSD$

PORTNAME=	fastest_sites
PORTVERSION=	20110317
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.semicomplete.com/files/fastest_sites/
DISTNAME=	${PORTNAME}-${PORTVERSION}.py
EXTRACT_SUFX=	# nada

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Sort MASTER_SITE_* based upon TCP handshake times

USES=		python shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/fastest_sites
SHEBANG_FILES=	fastest_sites-${PORTVERSION}.py

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fastest_sites-${PORTVERSION}.py \
		${STAGEDIR}${PREFIX}/bin/fastest_sites

.include <bsd.port.mk>
