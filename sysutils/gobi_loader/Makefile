PORTNAME=	gobi_loader
DISTVERSION=	g20191227
CATEGORIES=	sysutils net

MAINTAINER=	zarychtam@plan-b.pwste.edu.pl
COMMENT=	Firmware Loader for Qualcomm Gobi USB Chipsets
WWW=		https://github.com/kicer/gobi_loader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	mzary
GH_TAGNAME=	fbecd85

SUB_LIST+=	PREFIX=${PREFIX}
SUB_FILES=	gobi.conf.sample pkg-message

PLIST_FILES=	${PREFIX}/sbin/gobi_loader \
		"@sample ${PREFIX}/etc/devd/gobi.conf.sample"

do-install:
		${INSTALL_DATA} ${WRKSRC}/../gobi.conf.sample \
		    ${STAGEDIR}${PREFIX}/etc/devd/gobi.conf.sample
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/sbin

.include <bsd.port.mk>
