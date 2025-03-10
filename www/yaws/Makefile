PORTNAME=	yaws
PORTVERSION=	2.2.0
CATEGORIES=	www devel
MASTER_SITES=	https://codeload.github.com/erlyaws/yaws/tar.gz/refs/tags/${DISTNAME}?dummy=/

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Web server for dynamic content written in Erlang
WWW=		https://erlyaws.github.io/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	erl:lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		autoreconf cpe gmake libtool pathfix shebangfix

USE_GITHUB=	nodefault
GH_ACCOUNT=	erlyaws
GH_PROJECT=	yaws

SHEBANG_FILES=	www/cgi-bin/foo.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
CONFIGURE_ENV=	wwwdir=${WWWDIR} \
		yawsdir=${_APPDIR}

INSTALL_TARGET=	install-strip
PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	WWW
OPTIONS_SUB=	yes

WWW_DESC=	Install sample applications

_APPDIR=	${PREFIX}/lib/erlang/lib/yaws-${PORTVERSION}

.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKDIR}/yaws-yaws-* \
		${WRKDIR}/yaws-${PORTVERSION}
	@${FIND} ${WRKSRC} -name .empty -delete

post-patch:
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' \
		${WRKSRC}/man/yaws_api.5 \
		${WRKSRC}/man/yaws.conf.5
	@${FIND} ${WRKSRC} \( -name \*.orig -or -name \*.bak \) -delete

post-install:
.if ${PORT_OPTIONS:MWWW}
	${MV} ${STAGEDIR}${PREFIX}/www/www/* \
		${STAGEDIR}${WWWDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/www/www
.else
	${RM} -r ${STAGEDIR}${PREFIX}/www
.endif
	${MV} ${STAGEDIR}${PREFIX}/etc/yaws/dhparams.pem \
		${STAGEDIR}${PREFIX}/etc/yaws/dhparams.pem.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/yaws/yaws-cert.pem \
		${STAGEDIR}${PREFIX}/etc/yaws/yaws-cert.pem.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/yaws/yaws-key.pem \
		${STAGEDIR}${PREFIX}/etc/yaws/yaws-key.pem.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/yaws/yaws.conf.template \
		${STAGEDIR}${PREFIX}/etc/yaws/yaws.conf.sample

.include <bsd.port.mk>
