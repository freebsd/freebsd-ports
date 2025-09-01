PORTNAME=	jail_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
PORTREVISION=	37
CATEGORIES=	sysutils

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Prometheus exporter for FreeBSD jail metrics
WWW=		https://github.com/phyber/jail_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	phyber
USE_RC_SUBR=	jail_exporter

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/share/man/man8
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in CHANGELOG.md README.md
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
