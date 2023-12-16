PORTNAME=	bastille
DISTVERSION=	0.10.20231125
CATEGORIES=	sysutils

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Jail automation framework
WWW=		https://bastillebsd.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bastillebsd

NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/local/etc/bastille|${ETCDIR}|g' \
		-e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/usr/local/etc/rc.d/bastille

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/usr/local/bin/bastille ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/usr/local/etc/rc.d/bastille \
		${STAGEDIR}${PREFIX}/etc/rc.d

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/usr/local/share/bastille && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_MAN} ${WRKSRC}/usr/local/man/man8/bastille.8.gz \
		${STAGEDIR}${PREFIX}/man/man8/${PORTNAME}.8.gz
	${INSTALL_DATA} ${WRKSRC}/usr/local/etc/bastille/bastille.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.mk>
