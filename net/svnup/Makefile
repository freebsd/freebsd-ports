# $FreeBSD$

PORTNAME=	svnup
PORTVERSION=	1.08
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jmehr@umn.edu
COMMENT=	Lightweight program to pull source from an Apache Subversion server

LICENSE=	BSD2CLAUSE

USES=		tar:xz ssl
OPTIONS_DEFINE=	DOCS

CFLAGS+=		-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lmd -lssl

USE_GITHUB=	yes
GH_ACCOUNT=	johnmehr

PORTDOCS=	ChangeLog

post-patch:
	@${REINPLACE_CMD} -e 's|\/stable\/12|\/stable\/${OSREL:R}| ; \
		s|\/releng\/12.1|\/releng\/${OSREL}|' \
		${WRKSRC}/svnup.conf

do-build:
	cd ${WRKSRC} && \
		${CC} -o ${PORTNAME} ${CFLAGS} ${PORTNAME}.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
