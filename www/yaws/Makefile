# New ports collection makefile for:	yaws
# Date Created:				25 Jan 2004
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yaws
PORTVERSION=	1.94
CATEGORIES=	www
MASTER_SITES=	http://yaws.hyber.org/download/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A webserver for dynamic content written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/yaws-${PORTVERSION}
ONLY_FOR_ARCHS=	i386 amd64 sparc64

MAN1=		yaws.1
MAN5=		yaws.conf.5 yaws_api.5 yaws_soap_lib.5

OPTIONS_DEFINE=	SENDFILE
SENDFILE_DESC=	Use native sendfile(2) interface
OPTIONS_DEFAULT=SENDFILE

APPDIR=${PREFIX}/lib/erlang/lib/yaws-${PORTVERSION}

SUB_FILES=      pkg-message

CONFIGURE_ARGS+=--prefix=${PREFIX} --localstatedir=/var

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSENDFILE}
PLIST_SUB+=	SENDFILE=""
CONFIGURE_ARGS+=--enable-sendfile
.else
CONFIGURE_ARGS+=--disable-sendfile
PLIST_SUB+=	SENDFILE="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -name .empty -delete

post-patch:
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' \
		${WRKSRC}/man/yaws_api.5 ${WRKSRC}/man/yaws.conf.5 \
		${WRKSRC}/README
	@${FIND} ${WRKSRC} \( -name \*.orig -or -name \*.bak \) -delete

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/yaws ${PREFIX}/bin
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${FILESDIR}/yaws.conf.sample ${ETCDIR}
	@${MKDIR} ${APPDIR}/ebin
	@${MKDIR} ${APPDIR}/examples
	@${MKDIR} ${APPDIR}/examples/ebin
	@${MKDIR} ${APPDIR}/examples/src
	@${MKDIR} ${APPDIR}/include
	@${MKDIR} ${APPDIR}/priv
	@${MKDIR} ${APPDIR}/priv/lib
	@${MKDIR} ${APPDIR}/src
	@${MKDIR} ${PREFIX}/www/yaws
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${APPDIR}/ebin
	@${INSTALL_DATA} ${WRKSRC}/examples/ebin/* ${APPDIR}/examples/ebin
	@${INSTALL_DATA} ${WRKSRC}/examples/src/* ${APPDIR}/examples/src
.for FILE in envelope.xsd mime.types soap.xsd wsdl.xsd soap-envelope.xsd wsdl11soap12.xsd xml.xsd
	@${INSTALL_DATA} ${WRKSRC}/priv/${FILE} ${APPDIR}/priv
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/priv/epam ${APPDIR}/priv
	@${INSTALL_LIB} ${WRKSRC}/priv/lib/* ${APPDIR}/priv/lib
	@${INSTALL_DATA} ${WRKSRC}/include/* ${APPDIR}/include
	@${INSTALL_DATA} ${WRKSRC}/src/*.?rl ${APPDIR}/src
	@cd ${WRKSRC}/www && (${FIND} * | ${CPIO} -pu ${WWWDIR})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WWWDIR}
	@${INSTALL_MAN} ${WRKSRC}/man/*.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/man/*.5 ${MANPREFIX}/man/man5

post-install:
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${PREFIX}/lib/erlang/lib/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
