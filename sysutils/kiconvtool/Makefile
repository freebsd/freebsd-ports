PORTNAME=	kiconvtool
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to preload kernel iconv charset tables
WWW=		https://wiki.freebsd.org/DmitryMarakasov/kiconvtool

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3

USES=		iconv	# used by libkiconv, actually

PLIST_FILES=	sbin/${PORTNAME} etc/rc.d/kiconv \
		share/man/man8/${PORTNAME}.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
