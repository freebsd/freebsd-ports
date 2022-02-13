# Created by: Emanuel Haupt <ehaupt@critical.ch>

PORTNAME=	colordiff
PORTVERSION=	1.0.20
CATEGORIES=	textproc
MASTER_SITES=	http://www.colordiff.org/ LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to colorize diff output

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		shebangfix perl5
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	colordiff.pl

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/${PORTNAME}.pl ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${STAGEDIR}${PREFIX}/etc/colordiffrc.sample

.include <bsd.port.mk>
