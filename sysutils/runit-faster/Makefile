PORTNAME=	runit
DISTVERSION=	2.1.3.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/attachments/0f74bee0-05ce-40b4-9cdf-0f9f5a37f90b?dummy=/
PKGNAMESUFFIX=	-faster
DISTNAME=	freebsd-runit-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Runit based init replacement for ${OPSYS}
WWW=		https://codeberg.org/tobik/runit-faster

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

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|' ${WRKSRC}/Makefile

post-install:
# Micromanaging pkg-plist is no fun here...  Generate it on the fly
# instead.
	@${FIND} -s ${STAGEDIR}${PREFIX}/etc/sv -not -type d | ${SORT} | \
		${SED} -e 's,^${STAGEDIR},,' -e 's,^${PREFIX}/,,' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
