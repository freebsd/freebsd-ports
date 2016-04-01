# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	colorize
PORTVERSION=	0.3.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	admin@lissyara.su
COMMENT=	Robust log colorizer

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Term-ANSIColor>=0:devel/p5-Term-ANSIColor

USE_GITHUB=	yes
GH_ACCOUNT=	raszi

NO_BUILD=	yes
SUB_FILES=	pkg-message
USES=		shebangfix perl5
SHEBANG_FILES=	colorize

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/colorizerc|${PREFIX}/etc/colorizerc|' \
		${WRKSRC}/colorize

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/colorize ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/colorizerc ${STAGEDIR}${PREFIX}/etc/colorizerc.sample
	@${INSTALL_MAN} ${WRKSRC}/colorize.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
