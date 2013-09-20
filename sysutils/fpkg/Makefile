# Created by: Yuki SHIMAZU  <y.shimazu@nifty.com>
# $FreeBSD$

PORTNAME=	fpkg
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://voodoo.bawue.com/download/ \
		http://www.shimazu.org/fpkg/
DISTFILES=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	y.shimazu@nifty.com
COMMENT=	Package Tool Wrapper for FreeBSD

USES=		perl5
NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/fpkg

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
