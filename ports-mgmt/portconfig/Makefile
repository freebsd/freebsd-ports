PORTNAME=	portconfig
DISTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	ports-mgmt

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to set up FreeBSD port options
WWW=		https://gitlab.com/alfix/portconfig

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libbsddialog.a:devel/bsddialog

USES=		localbase:ldflags

USE_GITLAB=	yes
GL_ACCOUNT=	alfix

PLIST_FILES=	"@sample ${ETCDIR}/blackwhite.conf.sample" \
		"@sample ${ETCDIR}/default.conf.sample" \
		"@sample ${ETCDIR}/red-green.conf.sample" \
		"@sample ${ETCDIR}/yellow-blue.conf.sample" \
		bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

THEMES=		${WRKSRC}/themes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${THEMES}/blackwhite.conf ${STAGEDIR}${ETCDIR}/blackwhite.conf.sample
	${INSTALL_DATA} ${THEMES}/default.conf ${STAGEDIR}${ETCDIR}/default.conf.sample
	${INSTALL_DATA} ${THEMES}/red-green.conf ${STAGEDIR}${ETCDIR}/red-green.conf.sample
	${INSTALL_DATA} ${THEMES}/yellow-blue.conf ${STAGEDIR}${ETCDIR}/yellow-blue.conf.sample

.include <bsd.port.mk>
