# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	opendchub
PORTVERSION=	0.8.2
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/Open%20DC%20Hub/${PORTVERSION}

MAINTAINER=	yashin.dm@gmail.com
COMMENT=	Unofficial Unix version of the Direct Connect Hub software

USES=		perl5 gmake
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README configfiles general scriptdoc
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
pre-install:
	@${CHMOD} a+rx ${WRKSRC}/install-sh

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
