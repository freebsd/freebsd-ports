# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	resource-agents
PORTVERSION=	3.9.7
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	OCF Compliant Resource Agents

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

CONFLICTS=	heartbeat-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs
GH_PROJECT=	resource-agents

USES=		autoreconf gmake pkgconfig python shebangfix
USE_GCC=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ocf-root=${PREFIX}/etc/ocf

SHEBANG_LANG=	sh
sh_OLD_CMD=	${SH}
sh_CMD=		${LOCALBASE}/bin/bash
SHEBANG_FILES=	heartbeat/* \
		ldirectord/ldirectord.in \
		tools/ocft/ocft.in \
		tools/ocf-tester.in

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt

.include <bsd.port.mk>
