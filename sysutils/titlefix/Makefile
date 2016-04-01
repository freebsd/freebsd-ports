# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	titlefix
PORTVERSION=	0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renames files in a proper English title format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	id3v2:audio/id3v2

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
MAN1S=		titlefix.1 titlefixid3.1 titleid3.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@cd ${STAGEDIR}${PREFIX}/bin; ${LN} -sf ${PORTNAME} titlefixid3
	@cd ${STAGEDIR}${PREFIX}/bin; ${LN} -sf ${PORTNAME} titleid3
	@${INSTALL_MAN} ${MAN1S:S,^,${WRKSRC}/man1/,} ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
