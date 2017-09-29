# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	resource-agents
PORTVERSION=	4.0.1
PORTREVISION=	2
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

USES=		autoreconf gmake pkgconfig python shebangfix
USE_GCC=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

SHEBANG_LANG=	sh
sh_OLD_CMD=	/bin/sh
sh_CMD=		${LOCALBASE}/bin/bash
SHEBANG_FILES=	heartbeat/* \
		ldirectord/ldirectord.in \
		rgmanager/src/resources/*.sh \
		rgmanager/src/resources/*.sh.in \
		rgmanager/src/resources/ocf-shellfuncs \
		rgmanager/src/resources/svclib_nfslock \
		rgmanager/src/resources/utils/*.pl \
		rgmanager/src/resources/utils/*.sh \
		tools/ocft/ocft.in \
		tools/ocf-tester.in

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt

.include <bsd.port.mk>
