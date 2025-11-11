PORTNAME=	zogftw
DISTVERSION=	2025-02-23
DISTVERSIONSUFFIX=	-48a7d58
CATEGORIES=	sysutils
MASTER_SITES=	https://www.fabiankeil.de/sourcecode/zogftw/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Creates redundant backups on encrypted ZFS pools
WWW=		https://www.fabiankeil.de/gehacktes/zogftw/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	mbuffer:misc/mbuffer
TEST_DEPENDS=	atf-sh:devel/atf \
		kyua:devel/kyua

USES=		sudo
NO_BUILD=	yes
PORTSCOUT=	ignore:1

PLIST_FILES=	sbin/zogftw \
		share/man/man8/zogftw.8.gz

OPTIONS_DEFINE=		GNUPG
OPTIONS_DEFAULT=	GNUPG

GNUPG_RUN_DEPENDS=	gpg:security/gnupg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zogftw ${STAGEDIR}${PREFIX}/sbin/zogftw
	${INSTALL_MAN} ${WRKSRC}/zogftw.8 ${STAGEDIR}${PREFIX}/share/man/man8

do-test:
	${SETENV} HOME=${WRKDIR} ${LOCALBASE}/bin/kyua test --kyuafile ${WRKSRC}/tests/Kyuafile

.include <bsd.port.mk>
