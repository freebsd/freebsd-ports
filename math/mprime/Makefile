# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mprime
PORTVERSION=	26.6
CATEGORIES=	math benchmarks net
MASTER_SITES=	http://www.mersenne.org/ftp_root/gimps/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}-${OPSYS}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	mersenne.org distributed Great Internet Mersenne Prime Search

LIB_DEPENDS=	libcrypto.so.6:misc/compat9x

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message wrapper.sh

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprime ${STAGEDIR}${PREFIX}/bin/mprime-real
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/mprime

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
