PORTNAME=	pam_worker
DISTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://fossil.nours.eu/${PORTNAME}/tarball/?r=${DISTVERSION}&name=./

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	PAM authentication helper for use with
WWW=		https://fossil.nours.eu/pam_worker

LICENSE=	BSD2CLAUSE

PLIST_FILES=	"@(root,wheel,2755) bin/${PORTNAME}" \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.8.gz ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>

