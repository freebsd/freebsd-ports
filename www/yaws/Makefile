# $FreeBSD$

PORTNAME=	yaws
PORTVERSION=	2.0.4
CATEGORIES=	www devel
MASTER_SITES=	http://yaws.hyber.org/download/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web server for dynamic content written in Erlang

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	erl:lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_SUB=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		autoreconf gmake libtool pathfix shebangfix
SHEBANG_FILES=	www/cgi-bin/foo.py

OPTIONS_DEFINE=	WWW

WWW_DESC=	Install sample applications

APPDIR=		${PREFIX}/lib/erlang/lib/yaws-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
CONFIGURE_ENV=	wwwdir=${WWWDIR} yawsdir=${APPDIR}
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name .empty -delete

post-patch:
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' \
		${WRKSRC}/man/yaws_api.5 \
		${WRKSRC}/man/yaws.conf.5
	@${FIND} ${WRKSRC} \( -name \*.orig -or -name \*.bak \) -delete

post-install:
.if ${PORT_OPTIONS:MWWW}
	${MV} ${STAGEDIR}${PREFIX}/www/www/* ${STAGEDIR}${WWWDIR}
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
