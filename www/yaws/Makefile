# New ports collection makefile for:	yaws
# Date Created:				25 Jan 2004
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yaws
PORTVERSION=	1.40
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	erlyaws

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A webserver for dynamic content written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		yaws.1
MAN5=		yaws.conf.5 yaws_api.5

post-extract:
	@${RM} -r ${WRKSRC}/www/.xvpics ${WRKSRC}/www/testdir
	@${FIND} ${WRKSRC} -name .empty | ${XARGS} ${RM}

post-patch:
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' \
		${WRKSRC}/man/yaws_api.5 ${WRKSRC}/man/yaws.conf.5 \
		${WRKSRC}/src/yaws_config.erl ${WRKSRC}/scripts/yaws.ss
	@${FIND} ${WRKSRC} -name \*.orig -or -name \*.bak | ${XARGS} ${RM}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/yaws ${PREFIX}/bin
	@${INSTALL_DATA} ${FILESDIR}/yaws.conf.sample ${PREFIX}/etc/
	@${MKDIR} ${PREFIX}/lib/yaws/ebin
	@${MKDIR} ${PREFIX}/lib/yaws/include
	@${MKDIR} ${PREFIX}/lib/yaws/priv
	@${MKDIR} ${PREFIX}/www/yaws
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/yaws/ebin
	@${INSTALL_DATA} ${WRKSRC}/priv/* ${PREFIX}/lib/yaws/priv
	@${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/lib/yaws/include
	@cd ${WRKSRC}/www && (${FIND} * | ${CPIO} -puv ${PREFIX}/www/yaws)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/www/yaws
	@${INSTALL_MAN} ${WRKSRC}/man/*.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/man/*.5 ${MANPREFIX}/man/man5
	@${MKDIR} /var/log/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/yaws.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
