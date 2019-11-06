# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	scnc
PORTVERSION=	1.05
CATEGORIES=	net security
MASTER_SITES=	http://gomor.org/files/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	SSL Capable Netcat

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6

USES=		shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/scnc
SHEBANG_FILES=	scnc

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
