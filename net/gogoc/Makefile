# Created by: Tomaž Muraus <kami@k5-storitve.net>
# $FreeBSD$

PORTNAME=	gogoc
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://gogo6.com/downloads/
DISTNAME=	gogoc-1_2-RELEASE

MAINTAINER=	kami@k5-storitve.net
COMMENT=	GogoCLIENT, connect to Freenet6 tunnel

USES=		gmake ssl
USE_RC_SUBR=	gogoc

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	CLIENT-LICENSE.TXT GUI-LICENSE.TXT INSTALL README

SUB_FILES=	gogoc
SUB_LIST=	LOCALBASE=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct dsa_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct dsa_st'
.endif

do-install:
	cd ${WRKSRC}/gogoc-tsp/ && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} \
	    ${MAKE_CMD} platform=freebsd installdir=${STAGEDIR}${PREFIX} install
	${RM} ${STAGEDIR}${PREFIX}/bin/gogoc.conf*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gogoc
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gogoc-tsp/bin/gogoc.conf.sample ${STAGEDIR}${EXAMPLESDIR}
	@${REINPLACE_CMD} -e \
	    's|gogoc_dir=${STAGEDIR}${PREFIX}|gogoc_dir=${PREFIX}|g' \
	    ${STAGEDIR}${EXAMPLESDIR}/gogoc.conf.sample
	@${RM} ${STAGEDIR}${EXAMPLESDIR}/gogoc.conf.sample.bak # pass stage-qa
	${INSTALL_DATA} ${STAGEDIR}${EXAMPLESDIR}/gogoc.conf.sample \
	    ${STAGEDIR}${PREFIX}/etc/gogoc.conf
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
