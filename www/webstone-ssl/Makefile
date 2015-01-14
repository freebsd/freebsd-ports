# Created by: Kazumasa Nishizawa <k_nishizawa@anet.ne.jp>
# $FreeBSD$

PORTNAME=	webstone
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	www benchmarks
MASTER_SITES=	http://crypto.stanford.edu/~nagendra/projects/WebStone/download/
PKGNAMESUFFIX=	-ssl
DISTNAME=	WebStone-SSL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	World wide web server benchmarking with SSL support

WRKSRC=		${WRKDIR}/WebStone${PORTVERSION}/src

GNU_CONFIGURE=	yes
USES=		tar:tgz
USE_OPENSSL=	yes
ALL_TARGET=	install
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

do-install:
	@${RMDIR} ${WRKSRC}/../bin/runs
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone-ssl/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone-ssl/conf
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone-ssl/lgm
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${STAGEDIR}${PREFIX}/webstone-ssl/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../lgm/* ${STAGEDIR}${PREFIX}/webstone-ssl/lgm
	${INSTALL_DATA} ${WRKSRC}/../conf/* ${STAGEDIR}${PREFIX}/webstone-ssl/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../webstone  ${STAGEDIR}${PREFIX}/webstone-ssl
	@${MKDIR} ${WRKSRC}/../bin/runs
.for i in webclient webmaster genrand
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/webstone-ssl/bin/${i}
.endfor
.for i in ws20_cgi ws25_cgi
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/webstone-ssl/lgm/${i}
.endfor

.include <bsd.port.mk>
