# Created by: Nicolas Goralski <nicolas@goralski.fr>
# $FreeBSD$

PORTNAME=	librenms-agent
PORTVERSION=	0.3
CATEGORIES=	net-mgmt

MAINTAINER=	kiwi@oav.net
COMMENT=	Agents and plugins for librenms

LICENSE=	GPLv2

USES=		shebangfix python:2:run php:cli
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	librenms
GH_TAGNAME=	fb678cb

NO_BUILD=	yes

SHEBANG_FILES=	agent-local/*

RUN_DEPENDS+=	xinetd:security/xinetd \
		bash:shells/bash

LIB_DEPENDS+=	libstatgrab.so:devel/libstatgrab \

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/check_mk_agent_freebsd
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/mk_enplug
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/check_mk_xinetd

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xinetd.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/check_mk_agent/plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/check_mk_agent/repo
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/check_mk_agent/local
	${INSTALL_SCRIPT} ${WRKSRC}/check_mk_agent_freebsd ${STAGEDIR}${PREFIX}/bin/check_mk_agent
	${INSTALL_SCRIPT} ${WRKSRC}/mk_enplug ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/check_mk_xinetd ${STAGEDIR}${PREFIX}/etc/xinetd.d/check_mk
	${INSTALL_SCRIPT} ${WRKSRC}/snmp/distro ${STAGEDIR}${PREFIX}/bin

	@cd ${WRKSRC} ; \
	for agent_local in $$( ${FIND} ./agent-local -type f ! -name README ); do \
		${INSTALL_SCRIPT} "$$agent_local" ${STAGEDIR}${PREFIX}/lib/check_mk_agent/repo/ ; \
	done

.include <bsd.port.mk>
