# New ports collection makefile for:	opendchub
# Date created:			May 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	opendchub
PORTVERSION=	0.7.16
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/Open%20DC%20Hub/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial Unix version of the Direct Connect Hub software

USE_PERL5=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

PORTDOCS=	README configfiles general scriptdoc
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
