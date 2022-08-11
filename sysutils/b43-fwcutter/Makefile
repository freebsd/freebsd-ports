PORTNAME=	b43-fwcutter
PORTVERSION=	019
CATEGORIES=	sysutils
MASTER_SITES=	https://bues.ch/b43/fwcutter/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Firmware extractor for Broadcom wireless adapters

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bzip2

MAKE_ARGS=	V=1

PLIST_FILES=	bin/b43-fwcutter \
		man/man1/b43-fwcutter.1.gz

.include <bsd.port.mk>
