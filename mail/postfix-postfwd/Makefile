# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	postfwd
PORTVERSION=	1.35
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.${PORTNAME}.org/old/
PKGNAMEPREFIX=	postfix-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Postfix firewall policy daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-Server>=0:net/p5-Net-Server

NO_ARCH=	yes
SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}
USES=		perl5 shebangfix
SHEBANG_FILES=	sbin/* tools/*.pl tools/hapolicy/*
USE_PERL5=	run
NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES DOCS POSTFWD2
POSTFWD2_DESC=	Install postfwd v2 rather than v1

do-install:
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.cf.sample ${STAGEDIR}${ETCDIR}
	@${INSTALL_MAN} ${WRKSRC}/man/man8/* ${STAGEDIR}${MANPREFIX}/man/man8

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tools/request.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/postfwd.plugins.sample ${STAGEDIR}${EXAMPLESDIR}

do-install-POSTFWD2-on:
	@${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME}2 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-POSTFWD2-off:
	@${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
