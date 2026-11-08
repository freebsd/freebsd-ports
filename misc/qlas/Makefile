PORTNAME=	qlas
DISTVERSIONPREFIX=	v
DISTVERSION=	1.94
CATEGORIES=	misc

MAINTAINER=	i@vlad.guru
COMMENT=	Qico FIDO mailer log analyzer and statistic builder
WWW=		https://gitlab.com/muvo/qlas

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix perl5 shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	muvo
GL_TAGNAME=	3c07302618c3a014d1df1c4766a494fd7cc68b50

SHEBANG_FILES=	qlas

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/qlas \
		"@sample etc/qlas.cfg.sample"

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/qlas

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qlas ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qlas.conf.default ${STAGEDIR}${PREFIX}/etc/qlas.cfg.sample

.include <bsd.port.mk>
