# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	runit
DISTVERSION=	${RUNITVERSION}-${CONFVERSION}
RUNITVERSION=	2.1.2
CONFVERSION=	0.1.34
CATEGORIES=	sysutils
MASTER_SITES=	http://smarden.org/runit/ \
		http://www.bayofrum.net/dist/runit/ \
		https://github.com/t6/freebsd-runit/releases/download/v${CONFVERSION}/:config \
		LOCAL/tobik:config \
		https://pkg.tobik.me/distfiles/:config
PKGNAMESUFFIX=	-faster
DISTFILES=	runit-${RUNITVERSION}${EXTRACT_SUFX} \
		freebsd-runit-${CONFVERSION}${EXTRACT_SUFX}:config

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Runit based init replacement for ${OPSYS}

LICENSE=	BSD3CLAUSE CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/package/COPYING
LICENSE_FILE_CC0-1.0=	${WRKDIR}/freebsd-runit-${CONFVERSION}/README.md

RUN_DEPENDS=	snooze:sysutils/snooze

CONFLICTS_INSTALL=	runit

PLIST_SUB=	RUNITDIR=${RUNITDIR}
SUB_FILES=	pkg-message
SUB_LIST=	RUNITDIR=${RUNITDIR}
USE_RC_SUBR=	runsvdir
WRKSRC=		${WRKDIR}/admin/runit-${RUNITVERSION}

OPTIONS_DEFINE=	DOCS ROOT
OPTIONS_SUB=	yes

ROOT_DESC=	Install bootstrap files into /etc/runit and /sbin

PORTDOCS=	*

ROOT_VARS=	RUNITDIR=/etc/runit SBINDIR=/sbin
ROOT_VARS_OFF=	RUNITDIR=${ETCDIR} SBINDIR=${PREFIX}/sbin

post-patch:
	@${REINPLACE_CMD} -e 's,/service/,/var/service,' \
		-e 's,/etc/runit,${RUNITDIR},' \
		-e 's,/sbin/runit,${SBINDIR}/runit,' \
		${WRKSRC}/man/* ${WRKSRC}/doc/*.html \
		${WRKSRC}/src/sv.c \
		${WRKSRC}/src/runsvchdir.c \
		${WRKSRC}/src/runit.c \
		${WRKSRC}/src/runit.h

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	@${ECHO_CMD} "${CC}" > ${WRKSRC}/src/conf-ld

do-build:
	@cd ${WRKSRC} && package/compile

do-install:
	@${MKDIR} ${STAGEDIR}${RUNITDIR} ${STAGEDIR}${SBINDIR}
	cd ${WRKSRC}/command && ${INSTALL_PROGRAM} runit runit-init \
		${STAGEDIR}${SBINDIR}
	cd ${WRKSRC}/command && ${INSTALL_PROGRAM} \
		chpst runsv runsvchdir runsvdir sv svlogd utmpset \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${STAGEDIR}${PREFIX}/man/man8
	@${DO_MAKE_BUILD} -C ${WRKDIR}/freebsd-runit-${CONFVERSION} \
		DESTDIR=${STAGEDIR} \
		LOCALBASE=${LOCALBASE} \
		PREFIX=${PREFIX} \
		RUNITDIR=${RUNITDIR} \
		SVDIR=${PREFIX}/etc/sv \
		install
# Point runit to the run directory (a necessity to let runit work on
# read-only root filesystems) and make sure rebooting and powering off
# can work correctly.
	@${LN} -s /var/run/runit/reboot ${STAGEDIR}${RUNITDIR}/reboot
	@${LN} -s /var/run/runit/stopit ${STAGEDIR}${RUNITDIR}/stopit

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} \
		package/CHANGES package/README package/THANKS doc/*.html \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/freebsd-runit-${CONFVERSION}/docs/runit-faster.md \
		${STAGEDIR}${DOCSDIR}

post-install:
# Micromanaging pkg-plist is no fun here...  Generate it on the fly
# instead.
	@${FIND} -s ${STAGEDIR}${PREFIX}/etc/sv -not -type d | ${SORT} | \
		${SED} -e 's,^${STAGEDIR},,' -e 's,^${PREFIX}/,,' \
		>> ${TMPPLIST}

do-test:
	@cd ${WRKSRC} && package/check

.include <bsd.port.mk>
