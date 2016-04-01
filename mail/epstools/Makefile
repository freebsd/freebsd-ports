# Created by: ismail@enderunix.org
# $FreeBSD$

PORTNAME=	epstools
PORTVERSION=	1.8
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/eps/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	EPS (Email Parsing System) sample tools

BUILD_DEPENDS=	${LOCALBASE}/lib/libeps.a:mail/eps
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTDOCS=	README

MAKE_ENV+=	DEFS="-I${LOCALBASE}/include/eps ${CFLAGS}"
SUB_FILES=	pkg-message

EXAMPLE_FILES=	addr.1 addr.2 addr.3 addr.4 email.1 email.2 virus.email
INSTALL_FILES=	address b64decode b64encode body fold full headers qpdecode \
		rewrite

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC \?=|' \
		-e 's|^DEFS =|DEFS \?=|' \
		-e 's|^LIBS = -leps|LIBS = ${LOCALBASE}/lib/libeps.a|' \
			${WRKSRC}/Makefile

do-install:
.for f in ${INSTALL_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/eps-${f}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/content/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
