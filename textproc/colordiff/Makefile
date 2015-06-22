# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	colordiff
PORTVERSION=	1.0.14
CATEGORIES=	textproc
MASTER_SITES=	http://www.colordiff.org/ LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to colorize diff output

LICENSE=	GPLv2

USES=		shebangfix perl5
NO_BUILD=	yes

SHEBANG_FILES=	colordiff.pl

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/${PORTNAME}.pl ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${STAGEDIR}${PREFIX}/etc/colordiffrc.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/colordiffrc)
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${STAGEDIR}${PREFIX}/etc
.endif

.include <bsd.port.mk>
