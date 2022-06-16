# Created by: petef@FreeBSD.org

PORTNAME=	colorize
PORTVERSION=	0.3.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Robust log colorizer

LICENSE=	GPLv2+

USES=		shebangfix perl5

NO_BUILD=	yes

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	raszi

SHEBANG_FILES=	colorize

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFFIX%%|${PREFIX}|' ${WRKSRC}/colorize

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/colorize ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/colorizerc ${STAGEDIR}${PREFIX}/etc/colorizerc.sample
	${INSTALL_MAN} ${WRKSRC}/colorize.1.gz ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
