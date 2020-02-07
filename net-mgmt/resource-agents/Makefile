# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	resource-agents
PORTVERSION=	4.4.0
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	OCF Compliant Resource Agents

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake gnome pkgconfig python shebangfix
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-fatal-warnings --with-version=${PORTVERSION} \
		PACKAGE_STRING="${PORTNAME} ${PORTVERSION}" \
		PACKAGE_VERSION="${PORTVERSION}"

CONFLICTS=	heartbeat-[0-9]*

SHEBANG_LANG=	sh
sh_OLD_CMD=	/bin/sh
sh_CMD=		${LOCALBASE}/bin/bash
SHEBANG_FILES=	heartbeat/* \
		ldirectord/ldirectord.in \
		rgmanager/src/resources/*.sh.in \
		rgmanager/src/resources/utils/*.pl \
		rgmanager/src/resources/utils/*.sh \
		tools/ocft/ocft.in \
		tools/ocf-tester.in

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt

post-patch:
	${REINPLACE_CMD} 's|v=UNKNOWN|v=${PORTVERSION}|g' \
	  ${WRKSRC}/make/git-version-gen
	${REINPLACE_CMD} 's|/etc/cluster|${LOCALBASE}/etc/cluster|g' \
	  ${WRKSRC}/heartbeat/sybaseASE.in \
	  ${WRKSRC}/rgmanager/src/resources/utils/config-utils.sh.in \
	  ${WRKSRC}/rgmanager/src/resources/ASEHAagent.sh.in

post-install:
	${RM} ${STAGEDIR}/${LOCALBASE}/resource-agents.conf

.include <bsd.port.mk>
