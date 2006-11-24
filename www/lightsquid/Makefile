# New ports collection makefile for:	lightsquid
# Date created:				24 Nov 2005
# Whom:					Alexander Logvinov <info@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	lightsquid
PORTVERSION=	1.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@logvinov.com
COMMENT=	A light and fast web based squid proxy traffic analyser

OPTIONS=	GDSUPPORT	"Graphics report support"	on

NO_BUILD=	yes
USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
DSTDIR=		${PREFIX}/www/${PORTNAME}
.if !defined(NOPORTDOCS)
SUB_LIST=	DOCSDIR=${DOCSDIR}
SUB_FILES=	pkg-message
.endif
CONFIGS=	lightsquid.cfg realname.cfg skipuser.cfg group.cfg
REINPLACE_ARGS=	-i ""
PORTDOCS=	gnugpl.txt install.txt readme.txt thanks.txt graph.txt logformat.txt \
		templates.txt version.txt

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GDSUPPORT)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
.endif

do-patch:
	@${REINPLACE_CMD} "s|/var/www/html/${PORTNAME}|${DSTDIR}|" ${WRKSRC}/lightsquid.cfg
	@${MV} ${WRKSRC}/group.cfg.src ${WRKSRC}/group.cfg
.for i in ${CONFIGS}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.dist
.endfor

do-install:
	@${MKDIR} ${DSTDIR}
	${CP} -R ${WRKSRC}/ ${DSTDIR}
	@${RM} -r ${DSTDIR}/doc
.for i in ${CONFIGS}
	@${CP} -n ${DSTDIR}/${i}.dist ${DSTDIR}/${i}
.endfor
	@${CHMOD} +x ${DSTDIR}/*.cgi
	@${CHMOD} +x ${DSTDIR}/*.pl
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DSTDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
