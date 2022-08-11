PORTNAME=	socat
DISTVERSION=	1.7.4.3
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Multipurpose relay and more

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler cpe ssl tar:bzip2
CPE_VENDOR=	dest-unreach
USE_RC_SUBR=	socat

GNU_CONFIGURE=	yes

PORTSCOUT=	skipv:2.0.0-b2

PLIST_FILES=	bin/filan \
		bin/procan \
		bin/socat \
		"@sample etc/socat-instances.conf.sample" \
		man/man1/socat.1.gz
PORTDOCS=	EXAMPLES FAQ README SECURITY

OPTIONS_DEFINE=	DOCS READLINE

READLINE_USES=			readline
READLINE_CONFIGURE_ENABLE=	readline

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} != base
USES+=		localbase
.endif

do-install:
.for f in filan procan socat
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/socat-instances.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.post.mk>
