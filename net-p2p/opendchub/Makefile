# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	opendchub
PORTVERSION=	0.8.3
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/Open%20DC%20Hub/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Unofficial Unix version of the Direct Connect Hub software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 gmake localbase ssl
GNU_CONFIGURE=	yes
# Fix build with clang 11
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README configfiles general scriptdoc
PLIST_FILES=	bin/${PORTNAME}

pre-install:
	@${CHMOD} a+rx ${WRKSRC}/install-sh

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
