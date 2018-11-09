# $FreeBSD$

PORTNAME=	statsite
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	rbarabas@rbarabas.info
COMMENT=	C implementation of statsd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf python:env
GNU_CONFIGURE=	yes
USE_CSTD=	gnu99
USE_GITHUB=	yes
GH_ACCOUNT=	armon

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USERS=		statsd
GROUPS=		statsd
USE_RC_SUBR=	statsite

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} -e 's,python,${PYTHON_CMD},' \
		-e 's,/usr/libexec/statsite,${DATADIR},' \
		-e '/daemonize/d' \
		-e '/pid_file/d' \
		${WRKSRC}/rpm/statsite.conf.example

post-install:
	${INSTALL_DATA} ${WRKSRC}/rpm/statsite.conf.example \
		${STAGEDIR}${PREFIX}/etc/statsite.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
