# Ports collection makefile for:  pear-HTTP_Header
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Header
PORTVERSION=	0.1.5
CATEGORIES=	www devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR OO-Interface to modify HTTP-Headers easily

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/Header_Cache.php ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

do-install:
	@${MKDIR} ${PEARDIR}/Header
	@${CP} ${WRKSRC}/Header/Cache.php ${PEARDIR}/Header
	@${CP} ${WRKSRC}/Header.php ${PEARDIR}
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Header.php
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Header

.include <bsd.port.post.mk>
