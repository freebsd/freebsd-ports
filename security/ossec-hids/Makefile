# $FreeBSD$

PORTNAME=	ossec-hids
PORTVERSION=	3.3.0
PORTREVISION=	0
CATEGORIES=	security

MAINTAINER=	dominik.lisiak@bemsoft.pl
COMMENT=	Security tool to monitor and check logs and intrusions

LICENSE=	GPLv2

RUN_DEPENDS=	ossec-hids-${OSSEC_TYPE}>=${PORTVERSION}:security/ossec-hids-${OSSEC_TYPE}

USES=		metaport

OPTIONS_DEFINE=		CONFIG

OPTIONS_SINGLE=		G_TYPE
OPTIONS_SINGLE_G_TYPE=	LOCAL AGENT SERVER

OPTIONS_DEFAULT=	CONFIG LOCAL

CONFIG_DESC=		Install configuration manager and samples
G_TYPE_DESC=		Installation type
LOCAL_DESC=		Analizes local data only (standalone)
AGENT_DESC=		Sends local data to the server for analysis
SERVER_DESC=		Analizes local data and data received from multiple agents

CONFIG_VARS=		RUN_DEPENDS+=ossec-hids-${OSSEC_TYPE}-config>=${PORTVERSION}:security/ossec-hids-${OSSEC_TYPE}-config
LOCAL_VARS=		OSSEC_TYPE=local
AGENT_VARS=		OSSEC_TYPE=agent
SERVER_VARS=		OSSEC_TYPE=server

.include <bsd.port.mk>
