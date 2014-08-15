# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mcollective-shell-client
PORTVERSION=	0.0.1
CATEGORIES=	sysutils
DISTNAME=	mcollective-shell-agent-${PORTVERSION}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	MCollective shell client plugin

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	mcollective>=2.2.4:${PORTSDIR}/sysutils/mcollective

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-mcollective-shell-agent-${GH_COMMIT}

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9fb27d5

PLIST_FILES=	share/mcollective/application/shell/watcher.rb \
		share/mcollective/application/shell/prefix_stream_buf.rb \
		share/mcollective/application/shell.rb
PLIST_DIRSTRY=	share/mcollective/application/shell

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_DIRSTRY}
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/application/shell/watcher.rb ${STAGEDIR}${PREFIX}/share/mcollective/application/shell/
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/application/shell/prefix_stream_buf.rb ${STAGEDIR}${PREFIX}/share/mcollective/application/shell/
	${INSTALL_DATA} ${WRKSRC}/lib/mcollective/application/shell.rb ${STAGEDIR}${PREFIX}/share/mcollective/application/

.include <bsd.port.mk>
