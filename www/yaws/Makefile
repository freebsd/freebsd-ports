# $FreeBSD$

PORTNAME=	yaws
PORTVERSION=	1.98
CATEGORIES=	www devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web server for dynamic content written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_AUTOTOOLS=	autoconf
USE_GITHUB=	yes

GH_ACCOUNT=	klacke
GH_PROJECT=	yaws
GH_COMMIT=	83bdc80
GH_TAGNAME=	yaws-${PORTVERSION}

MAN1=		yaws.1
MAN5=		yaws.conf.5 yaws_api.5 yaws_soap_lib.5

APPDIR=		${PREFIX}/lib/erlang/lib/yaws-${PORTVERSION}

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--prefix=${STAGEDIR}${PREFIX} --localstatedir=/var

.include <bsd.port.pre.mk>

post-extract:
	@${FIND} ${WRKSRC} -name .empty -delete

post-patch:
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' \
		${WRKSRC}/man/yaws_api.5 \
		${WRKSRC}/man/yaws.conf.5 \
		${WRKSRC}/README \
		${WRKSRC}/scripts/gen-yaws \
		${WRKSRC}/scripts/gen-yaws-generated
	@${REINPLACE_CMD} -e 's|!!VERSION!!|${PORTVERSION}|g' \
		${WRKSRC}/scripts/gen-yaws
	@${FIND} ${WRKSRC} \( -name \*.orig -or -name \*.bak \) -delete

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/yaws ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${FILESDIR}/yaws.conf.sample ${STAGEDIR}${ETCDIR}/yaws.conf.dist
	@${MKDIR} ${STAGEDIR}${APPDIR}/ebin
	@${MKDIR} ${STAGEDIR}${APPDIR}/examples
	@${MKDIR} ${STAGEDIR}${APPDIR}/examples/ebin
	@${MKDIR} ${STAGEDIR}${APPDIR}/examples/src
	@${MKDIR} ${STAGEDIR}${APPDIR}/include
	@${MKDIR} ${STAGEDIR}${APPDIR}/priv
	@${MKDIR} ${STAGEDIR}${APPDIR}/priv/lib
	@${MKDIR} ${STAGEDIR}${APPDIR}/src
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/yaws
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${APPDIR}/ebin
	@${INSTALL_DATA} ${WRKSRC}/examples/ebin/* ${STAGEDIR}${APPDIR}/examples/ebin
	@${INSTALL_DATA} ${WRKSRC}/examples/src/* ${STAGEDIR}${APPDIR}/examples/src
.for FILE in envelope.xsd mime.types soap.xsd wsdl.xsd soap-envelope.xsd wsdl11soap12.xsd xml.xsd
	@${INSTALL_DATA} ${WRKSRC}/priv/${FILE} ${STAGEDIR}${APPDIR}/priv
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/priv/epam ${STAGEDIR}${APPDIR}/priv
	@${INSTALL_LIB} ${WRKSRC}/priv/lib/* ${STAGEDIR}${APPDIR}/priv/lib
	@${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${APPDIR}/include
	@${INSTALL_DATA} ${WRKSRC}/src/*.?rl ${STAGEDIR}${APPDIR}/src
	@cd ${WRKSRC}/www && (${FIND} * | ${CPIO} -pu ${STAGEDIR}${WWWDIR})
	@${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/man/*.5 ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.post.mk>
