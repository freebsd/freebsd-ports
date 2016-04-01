# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	massadmin
PORTVERSION=	2.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Send system commands to a group of remote servers simultaneously

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Expect>=1.21:lang/p5-Expect \
		p5-Net-Telnet>=3.03:net/p5-Net-Telnet \
		p5-Net-Ping>=2.36:net/p5-Net-Ping \
		p5-Proc-Queue>=1.23:devel/p5-Proc-Queue \
		p5-IO-Tty>=1.08:devel/p5-IO-Tty

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
PLIST_FILES=	bin/massadmin man/man1/massadmin.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
