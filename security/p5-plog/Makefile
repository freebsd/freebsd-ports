PORTNAME=	plog
PORTVERSION=	0.10
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
MASTER_SITES=	http://www.antibozo.net/ogata/webtools/
DISTFILES=	plog.pl

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Perl based ipfilter log reporter

USES=		perl5 shebangfix
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_BUILD=	yes
SHEBANG_FILES=	${WRKSRC}/plog.pl
PLIST_FILES=	bin/plog.pl

pre-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/plog.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
