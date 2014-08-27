# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	rude
PORTVERSION=	0.70
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rude is a Real-time UDP Data Emitter and Collector (crude)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/DOC/COPYING

RUN_DEPENDS=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	--with-debug-lvl=3
USES=		perl5 shebangfix
SHEBANG_FILES=	grude/grude
WRKSRC=		${WRKDIR}/${PORTNAME}
OPTIONS_DEFINE=	DOCS

DOC_FILES=	README README.rude README.crude TODO example.cfg
EXAMPLE_FILES=	crude_jitter.pl crude_parse.pl dump2trace.pl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/grude/grude ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/DOC/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/scripts/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
