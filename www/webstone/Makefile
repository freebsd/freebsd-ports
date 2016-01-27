# Created by: Soren Dossing <sauber@netcom.com>
# $FreeBSD$

PORTNAME=	webstone
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	www benchmarks
MASTER_SITES=	http://www.mindcraft.com/webstone/
DISTNAME=	ws25_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	World wide web server benchmarking

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	run
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/WebStone${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	install

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${FIND} ${WRKSRC}/bin -name "*.pl" -o -name "*.wpl" | ${XARGS} \
		${REINPLACE_CMD} -i '' -e '1s|.*perl.*|#!${perl_CMD}|'

do-install:
	@${RM} ${WRKSRC}/bin/runs/keepme
	@${RMDIR} ${WRKSRC}/bin/runs
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone/conf
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone/lgm
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/webstone/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lgm/* ${STAGEDIR}${PREFIX}/webstone/lgm
	${INSTALL_DATA} ${WRKSRC}/conf/* ${STAGEDIR}${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/webstone  ${STAGEDIR}${PREFIX}/webstone
	@${MKDIR} ${WRKSRC}/bin/runs
	@${TOUCH} ${WRKSRC}/bin/runs/keepme
.for file in webclient webmaster genrand
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/webstone/bin/${file}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/webstone/bin/${file}
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/webstone/bin/${file}
.endfor
.for file in ws20_cgi ws25_cgi
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/webstone/lgm/${file}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/webstone/lgm/${file}
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/webstone/lgm/${file}
.endfor

.include <bsd.port.mk>
