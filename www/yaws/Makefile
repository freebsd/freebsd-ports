# New ports collection makefile for:	yaws
# Date Created:				25 Jan 2004
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yaws
PORTVERSION=	1.56
CATEGORIES=	www
MASTER_SITES=	http://yaws.hyber.org/download/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A webserver for dynamic content written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		yaws.1
MAN5=		yaws.conf.5 yaws_api.5

APPDIR=${PREFIX}/lib/erlang/lib/yaws-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-extract:
	@${RM} -r ${WRKSRC}/www/.xvpics ${WRKSRC}/www/testdir
	@${FIND} ${WRKSRC} -name .empty | ${XARGS} ${RM}

post-patch:
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' \
		${WRKSRC}/man/yaws_api.5 ${WRKSRC}/man/yaws.conf.5 \
		${WRKSRC}/src/yaws_config.erl ${WRKSRC}/scripts/yaws.template
	@${FIND} ${WRKSRC} -name \*.orig -or -name \*.bak | ${XARGS} ${RM}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/yaws ${PREFIX}/bin
	@${INSTALL_DATA} ${FILESDIR}/yaws.conf.sample ${PREFIX}/etc/
	@${MKDIR} ${APPDIR}/ebin
	@${MKDIR} ${APPDIR}/include
	@${MKDIR} ${APPDIR}/priv
	@${MKDIR} ${APPDIR}/src
	@${MKDIR} ${PREFIX}/www/yaws
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${APPDIR}/ebin
	@${INSTALL_DATA} ${WRKSRC}/priv/* ${APPDIR}/priv
	@${INSTALL_DATA} ${WRKSRC}/include/* ${APPDIR}/include
	@${INSTALL_DATA} ${WRKSRC}/src/*.?rl ${APPDIR}/src
	@cd ${WRKSRC}/www && (${FIND} * | ${CPIO} -pu ${PREFIX}/www/yaws)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/www/yaws
	@${INSTALL_MAN} ${WRKSRC}/man/*.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/man/*.5 ${MANPREFIX}/man/man5
	@${MKDIR} /var/log/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/yaws.pdf ${DOCSDIR}
.endif

post-install:
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.post.mk>
