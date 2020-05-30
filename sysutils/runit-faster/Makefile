# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	runit
DISTVERSION=	2.1.3.6
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/t6/freebsd-runit/releases/download/v${DISTVERSION}/ \
		LOCAL/tobik
PKGNAMESUFFIX=	-faster
DISTNAME=	freebsd-runit-${DISTVERSION}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Runit based init replacement for ${OPSYS}

LICENSE=	BSD3CLAUSE CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	snooze:sysutils/snooze

USES=		tar:xz
USE_RC_SUBR=	runsvdir

MAKE_ENV=	RUNITDIR=${RUNITDIR} \
		SBINDIR=${SBINDIR} \
		SVDIR=${PREFIX}/etc/sv
TEST_TARGET=	check

CONFLICTS_INSTALL=	runit

SUB_LIST=	RUNITDIR=${RUNITDIR}
PLIST_SUB=	RUNITDIR=${RUNITDIR}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS ROOT
OPTIONS_SUB=	yes

ROOT_DESC=	Install bootstrap files into /etc/runit and /sbin

ROOT_VARS_OFF=	RUNITDIR=${ETCDIR} SBINDIR=${PREFIX}/sbin
ROOT_VARS=	RUNITDIR=/etc/runit SBINDIR=/sbin

post-install:
# Micromanaging pkg-plist is no fun here...  Generate it on the fly
# instead.
	@${FIND} -s ${STAGEDIR}${PREFIX}/etc/sv -not -type d | ${SORT} | \
		${SED} -e 's,^${STAGEDIR},,' -e 's,^${PREFIX}/,,' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
