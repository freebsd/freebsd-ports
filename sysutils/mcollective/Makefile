# Created by: Russell Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	mcollective
PORTVERSION=	2.5.2
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.puppetlabs.com/${PORTNAME}/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Modern scalable datacenter orchestration framework

RUN_DEPENDS=	rubygem-stomp>=0:${PORTSDIR}/devel/rubygem-stomp

NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	mcollectived

RUBY_SHEBANG_FILES=	bin/mcollectived bin/mco

# don't make .bak files
REINPLACE_ARGS=	-i ""

SCRIPTS=	mco

SUB_LIST+=	RUBY=${RUBY}

OPTIONS_DEFINE=	DOCS

do-patch:
	@${REINPLACE_CMD} -e "s|/etc/mcollective|${ETCDIR}|" \
	    ${WRKSRC}/bin/mcollectived \
		${WRKSRC}/etc/server.cfg.dist \
		${WRKSRC}/etc/client.cfg.dist \
		${WRKSRC}/lib/mcollective/config.rb \
		${WRKSRC}/lib/mcollective/util.rb \
		${WRKSRC}/lib/mcollective/rpc.rb
	@${REINPLACE_CMD} -e "s|/usr/libexec/mcollective|${PREFIX}/share|" \
	    ${WRKSRC}/etc/server.cfg.dist \
	    ${WRKSRC}/etc/client.cfg.dist

do-install:
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_SITELIBDIR})
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/plugins/mcollective && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${script} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mcollectived ${STAGEDIR}${PREFIX}/sbin/mcollectived

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/client.cfg.dist ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/server.cfg.dist ${STAGEDIR}${ETCDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
