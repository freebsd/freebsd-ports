# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmon
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bsdconsulting.no/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Near-realtime log monitoring tool, sends alerts on hits and misses

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail \
		p5-File-Tail>=0:${PORTSDIR}/devel/p5-File-Tail

USES=		perl5 tar:tgz
NO_BUILD=	yes

PORTDOCS=	README TODO
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/lmon.pl ${WRKSRC}/control.pl \
		${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/control.cfg \
		${STAGEDIR}${PREFIX}/${PORTNAME}/control.cfg.sample
	@${REINPLACE_CMD} -E -e "s@^(user=).*@\1\"root\"@;s@^(lmonhome=).*@\1\"${PREFIX}/${PORTNAME}\"@" ${WRKSRC}/examples/lmon.init
	${INSTALL_SCRIPT} ${WRKSRC}/examples/lmon.init \
		${STAGEDIR}${PREFIX}/etc/rc.d/lmon.sh.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.rules ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
