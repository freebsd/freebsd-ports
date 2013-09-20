# Created by: Adrian Chadd <adrian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squidstats
PORTVERSION=	54
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	squidstats-r${PORTVERSION}

MAINTAINER=	adrian@FreeBSD.org
COMMENT=	A collection of simple statistical analysis bits for Squid

RUN_DEPENDS=	p5-Config-IniFiles>=2.39:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-RRD-Simple>=1.44:${PORTSDIR}/databases/p5-RRD-Simple \
		p5-SNMP_Session>=1.11:${PORTSDIR}/net-mgmt/p5-SNMP_Session

USES=		perl5

SQUID_UID?=	squid
SQUID_GID?=	squid

SUB_FILES=	pkg-message pkg-install
SUB_LIST+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

NO_STAGE=	yes
pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_CMD} "===> post-installation information for ${PKGNAME}:"
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
