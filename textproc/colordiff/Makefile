# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	colordiff
PORTVERSION=	1.0.13
CATEGORIES=	textproc
MASTER_SITES=	http://www.colordiff.org/ CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to colorize diff output

LICENSE=	GPLv2

USES=		shebangfix perl5
NO_BUILD=	yes

SHEBANG_FILES=	colordiff.pl

MAN1=		colordiff.1

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/${MAN1}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${PREFIX}/etc/colordiffrc.default
.if !exists(${PREFIX}/etc/colordiffrc)
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${PREFIX}/etc
.endif

.include <bsd.port.mk>
