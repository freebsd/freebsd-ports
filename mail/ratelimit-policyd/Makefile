# Created by: Miroslav Lachman
# $FreeBSD$

PORTNAME=	ratelimit-policyd
PORTVERSION=	1.0.1
CATEGORIES=	mail

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	Sender rate limit policy daemon for Postfix

LICENSE=	NONE

USES+=		perl5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	MirLach
GH_PROJECT=	ratelimit-policyd
#GH_TAGNAME=	65154a2

RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql

SHEBANG_FILES=	ratelimit-policyd.pl

NO_BUILD=	yes

SUB_FILES=	pkg-message

PERIODIC_DAILY=	etc/periodic/daily

PLIST_FILES=	bin/ratelimit-policyd.pl \
	etc/rc.d/ratelimit-policyd \
	etc/ratelimit-policyd.cfg.sample \
	${PERIODIC_DAILY}/535.ratelimit-policyd

PORTDATA=	mysql-schema.sql
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/rc.d/ratelimit-policyd
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/ratelimit-policyd.pl
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
		${WRKSRC}/periodic/daily/535.ratelimit-policyd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ratelimit-policyd.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/ratelimit-policyd ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/ratelimit-policyd.cfg \
		${STAGEDIR}${PREFIX}/etc/ratelimit-policyd.cfg.sample

	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mysql-schema.sql ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

	@${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DAILY}
	${INSTALL_SCRIPT} ${WRKSRC}/periodic/daily/535.ratelimit-policyd \
		${STAGEDIR}${PREFIX}/${PERIODIC_DAILY}

.include <bsd.port.mk>
