PORTNAME=	zogftw
PORTVERSION=	0.0.2022.06.25
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.fabiankeil.de/sourcecode/zogftw/
DISTNAME=	${PORTNAME}-2022-06-25-03982c7

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Creates redundant backups on encrypted ZFS pools
WWW=		https://www.fabiankeil.de/gehacktes/zogftw/

RUN_DEPENDS=	mbuffer:misc/mbuffer \
		sudo:security/sudo

NO_BUILD=	yes
PORTSCOUT=	ignore:1

PLIST_FILES=	sbin/zogftw \
		share/man/man8/zogftw.8.gz

OPTIONS_DEFINE=		EXECUTE_TESTS GNUPG
OPTIONS_DEFAULT=	GNUPG
EXECUTE_TESTS_DESC=	Execute tests before staging. Adds build dependencies.

EXECUTE_TESTS_BUILD_DEPENDS=	atf-sh:devel/atf \
				kyua:devel/kyua

GNUPG_RUN_DEPENDS=	gpg:security/gnupg

.include <bsd.port.options.mk>

execute-tests: extract
.if ${PORT_OPTIONS:MEXECUTE_TESTS}
	${SETENV} HOME=${WRKDIR} kyua test --kyuafile ${WRKSRC}/tests/Kyuafile
.endif

do-install: execute-tests
	${INSTALL_SCRIPT} ${WRKSRC}/zogftw ${STAGEDIR}${PREFIX}/sbin/zogftw
	${INSTALL_MAN} ${WRKSRC}/zogftw.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
