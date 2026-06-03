PORTNAME=	sanoid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	sysutils

MAINTAINER=	hartzell@alerce.com
COMMENT=	Policy-driven snapshot management and replication tools
WWW=		https://github.com/jimsalterjrs/sanoid

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lzop:archivers/lzop \
		mbuffer:misc/mbuffer \
		pv:sysutils/pv \
		p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Config-IniFiles>=0:devel/p5-Config-IniFiles

USES=		perl5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	jimsalterjrs

USE_PERL5=	run
SHEBANG_FILES=	findoid sanoid sleepymutex syncoid

CONFLICTS_INSTALL=	sanoid-devel # bin/findoid

NO_ARCH=	yes
NO_BUILD=	yes

# line 19:  my %args = ("configdir" => "/etc/sanoid");
post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/sanoid|${PREFIX}/etc/sanoid|' \
		${WRKSRC}/sanoid
	@${REINPLACE_CMD} -i '' \
		-e 's|/usr/bin/lzop|${LOCALBASE}/bin/lzop|' \
		-e 's|/usr/bin/mbuffer|${LOCALBASE}/bin/mbuffer|' \
		-e 's|/usr/bin/pv|${LOCALBASE}/bin/pv|' \
		-e 's|/usr/bin/sudo|${LOCALBASE}/bin/sudo|' \
		${WRKSRC}/syncoid

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/findoid ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sanoid ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sleepymutex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/syncoid ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/sanoid.defaults.conf \
		${STAGEDIR}${ETCDIR}/sanoid.defaults.conf
	${INSTALL_DATA} ${WRKSRC}/sanoid.conf \
		${STAGEDIR}${ETCDIR}/sanoid.conf.sample

.include <bsd.port.mk>
