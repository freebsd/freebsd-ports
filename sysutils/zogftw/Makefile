# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	zogftw
PORTVERSION=	0.0.2015.11.21
CATEGORIES=	sysutils
MASTER_SITES=	https://www.fabiankeil.de/sourcecode/zogftw/
DISTNAME=	${PORTNAME}-2015-11-21-0a21288

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Creates redundant backups on encrypted ZFS pools

RUN_DEPENDS=	mbuffer:misc/mbuffer \
		sudo:security/sudo

OPTIONS_DEFINE=		EXECUTE_TESTS GNUPG
OPTIONS_DEFAULT=	GNUPG
EXECUTE_TESTS_DESC=	Execute tests before staging. Adds build dependencies.

PLIST_FILES=	sbin/zogftw \
		man/man8/zogftw.8.gz

NO_BUILD=	yes
PORTSCOUT=	ignore:1

GNUPG_RUN_DEPENDS=	gpg:security/gnupg

EXECUTE_TESTS_BUILD_DEPENDS=	atf-sh:devel/atf \
				kyua:devel/kyua

.include <bsd.port.options.mk>

execute-tests: extract
.if ${PORT_OPTIONS:MEXECUTE_TESTS}
	${SETENV} HOME=${WRKDIR} kyua test --kyuafile ${WRKSRC}/tests/Kyuafile
.endif

do-install: execute-tests
	${INSTALL_SCRIPT} ${WRKSRC}/zogftw ${STAGEDIR}${PREFIX}/sbin/zogftw
	${INSTALL_MAN} ${WRKSRC}/zogftw.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
