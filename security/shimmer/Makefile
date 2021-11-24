# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>

PORTNAME=	shimmer
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl implementation that hides a valuable port on your server

DEPRECATED=	Abandonware, last release in 2008
EXPIRATION_DATE=2022-03-31

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	shimmer shimmerd

PLIST_FILES=	bin/shimmer \
		bin/shimmerd \
		etc/shimmer.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shimmer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/shimmerd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/shimmer.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
