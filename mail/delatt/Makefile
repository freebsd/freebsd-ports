# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	delatt
DISTVERSION=	1.1.3
CATEGORIES=	mail
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Strip attachments from email

LICENSE=	GPLv2

RUN_DEPENDS=	p5-MIME-Base64>=0:converters/p5-MIME-Base64

USES=		shebangfix perl5
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	delatt
PLIST_FILES=	bin/delatt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
