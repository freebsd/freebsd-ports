# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mldonkey
PORTVERSION=	0.2
CATEGORIES=	net-p2p perl5
MASTER_SITES=	SF/remotefilesync/perlreactor/perlreactor%20${PORTVERSION}
PKGNAMESUFFIX=	-perlreactor
DISTNAME=	perlreactor_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically add links found in web pages to MLDonkey queue

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		shebangfix
SHEBANG_FILES$=${BINARY_NAME}

BINARY_NAME=	perlreactor

post-patch:
	@${REINPLACE_CMD} -i '' -e '1d'	${WRKSRC}/${BINARY_NAME}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${CHMOD} 0755 ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.mk>
