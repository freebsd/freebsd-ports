# New ports collection makefile for:   epstools
# Date created:                 21 Jul 2005
# Whom:				ismail@enderunix.org
#
# $FreeBSD$

PORTNAME=	epstools
PORTVERSION=	1.7
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/eps/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	EPS (Email Parsing System) sample tools

BUILD_DEPENDS=	${LOCALBASE}/lib/libeps.a:${PORTSDIR}/mail/eps
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

PORTDOCS=	README

MAKE_ENV+=	DEFS="-I${LOCALBASE}/include ${CFLAGS}"
SUB_FILES=	pkg-message

EXAMPLE_FILES=	addr.1 addr.2 addr.3 addr.4 email.1 email.2 virus.email
INSTALL_FILES=	address b64decode b64encode body fold full headers qpdecode rewrite

post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC \?=|' \
			  -e 's|^DEFS =|DEFS \?=|' \
			  -e 's|^LIBS = -leps|LIBS = ${LOCALBASE}/lib/libeps.a|' \
		${WRKSRC}/Makefile

do-install:
.for f in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/bin/eps-${f}
.endfor

	${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/content/${f} ${EXAMPLESDIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
