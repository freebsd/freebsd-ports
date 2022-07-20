PORTNAME=	wping
PORTVERSION=	0.1a
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based graphical ping log

RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD

NO_ARCH=	yes
USES=		perl5 tar:bzip2 shebangfix
SHEBANG_FILES=	wping.pl
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wping.pl ${STAGEDIR}${PREFIX}/bin/wping
	${INSTALL_DATA} ${WRKSRC}/wping.conf ${STAGEDIR}${PREFIX}/etc/wping.conf.sample

.include <bsd.port.mk>
