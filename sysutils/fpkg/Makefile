# Created by: Yuki SHIMAZU  <y.shimazu@nifty.com>
# $FreeBSD$

PORTNAME=	fpkg
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://voodoo.bawue.com/download/ \
		http://www.shimazu.org/fpkg/
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	y.shimazu@nifty.com
COMMENT=	Package Tool Wrapper for FreeBSD

BROKEN=		does not support pkg(8)
DEPRECATED=	Does not support pkg(8)
EXPIRATION_DATE=	2015-08-15

USES=		perl5 shebangfix
SHEBANG_FILES=	fpkg
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/fpkg

do-extract:
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
